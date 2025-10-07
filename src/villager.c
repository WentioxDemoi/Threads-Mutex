#include <stdio.h>
#include "../includes/villager.h"
#include "../includes/druid.h"

// Prints when a villager thread starts
void villager_print_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

// Prints drink attempt and safely decrements loads if available
void villager_print_need_drink(int id)
{
    pthread_mutex_lock(&mutex);
    if (loads > 0) {
        printf("Villager %d: I need a drink... I see %d servings left.\n", id, loads);
        loads--;
    } else {
        printf("Villager %d: I need a drink... I see 0 servings left.\n", id);
    }
    pthread_mutex_unlock(&mutex);
}

// Requests a refill from the druid if needed
void villager_print_call_druid(int id, int *needRefill, int refill_left)
{
    sem_wait(semaphore);
    if (loads > 0 || (loads <= 0 && refill_left == 0)) {
        sem_post(semaphore);
        return;
    }
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
    *needRefill = 1;

}

// Prints a fight action and decrement remaining fights
void villager_print_fight(int id, int *fights_left)
{
    *fights_left -= 1;
    printf("Villager %d: Take that roman scum! Only %d left.\n", id, *fights_left);
}

// Prints when a villager is done and goes to sleep
void villager_print_sleep(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}

