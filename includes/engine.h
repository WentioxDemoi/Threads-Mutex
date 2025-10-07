#ifndef ENGINE_H
#define ENGINE_H

// Starts the global engine (main logic)
void global_engine(char **av);

// Logic for the druid thread
void *druid_engine(void *args);

// Logic for the villager threads
void *villager_engine(void *args);

typedef struct druid_args_s {
    int *needRefill;
    int *refill_left;
} druid_args_t;

typedef struct villager_args_s {
    int *needRefill;
    int *refill_left;
    int nb_fights;
    int id;
} villager_args_t;

#endif // ENGINE_H