#include "../includes/includes.h"
#include "../includes/villager.h"
#include "../includes/druid.h"
#include "../includes/engine.h"

// Global synchronization primitive shared across threads
sem_t *semaphore;
// Current number of available servings in the cauldron
int loads;
// Maximum servings after a druid refill
int loadSize;

// Thread entrypoint for a single villager
void *villager_engine(void *args)
{
    villager_args_t *data = (villager_args_t *)args;
    villager_print_start(data->id);
    while (data->nb_fights > 0) {
        int current_loads;
        pthread_mutex_lock(&mutex);
        current_loads = loads;
        pthread_mutex_unlock(&mutex);
        // If no potion left and no refills remain, stop
        if (current_loads <= 0 && *data->refill_left == 0)
            break;
        if (current_loads <= 0) {
            villager_print_call_druid(data->id, data->needRefill, *data->refill_left);
        } else if (data->nb_fights > 0) {
            villager_print_need_drink(data->id);
            villager_print_fight(data->id, &data->nb_fights);
        }
        
    }

    villager_print_sleep(data->id);
    
    return NULL;
}

// Thread entrypoint for the druid (handles refills)
void *druid_engine(void *args)
{
    druid_args_t *data = (druid_args_t *)args;
    druid_print_ready();
    while (1)
    {
        if (*data->needRefill == 1)
        {
            druid_print_refill(*data->refill_left);
            *data->needRefill = 0;
            *data->refill_left -= 1;
        }
        if (*data->refill_left == 0)
        {
            druid_print_out_of_viscum();
            break;
        }
    }
    return NULL;
}

// Orchestrates threads and shared state initialization
void global_engine(char **av)
{
    sem_unlink("/panoramix_sem");
    
    semaphore = sem_open("/panoramix_sem", O_CREAT | O_EXCL, 0644, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }
    
    int needRefill = 0;
    int nb_villager = strtol(av[1], NULL, 10);
    int nb_fight = strtol(av[3], NULL, 10);
    int refill_left = strtol(av[4], NULL, 10);
    loadSize = strtol(av[2], NULL, 10);
    loads = loadSize;
    
    pthread_t druid_thread;
    pthread_t villager_thread[nb_villager];
    druid_args_t args = {&needRefill, &refill_left};
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&druid_thread, NULL, druid_engine, &args);
    
    villager_args_t *args2 = malloc(sizeof(villager_args_t) * nb_villager);
    
    for (int i = 0; i < nb_villager; i++)
    {
        args2[i].needRefill = &needRefill;
        args2[i].refill_left = &refill_left;
        args2[i].nb_fights = nb_fight;
        args2[i].id = i;
        pthread_create(&villager_thread[i], NULL, villager_engine, &args2[i]);
    }
    
    pthread_join(druid_thread, NULL);
    for (int i = 0; i < nb_villager; i++)
    {
        pthread_join(villager_thread[i], NULL);
    }
    
    sem_close(semaphore);
    sem_unlink("/panoramix_sem");
    free(args2);
}