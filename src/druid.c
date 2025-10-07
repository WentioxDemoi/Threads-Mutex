#include <stdio.h>
#include "../includes/druid.h"
#include "../includes/villager.h"

// Prints when the druid thread starts
void druid_print_ready(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

// Prints a refill and resets the cauldron to full
void druid_print_refill(int refill_left)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make %d more refills after this one.\n", refill_left);
    loads = loadSize;
    sem_post(semaphore);
}

// Prints when the druid cannot brew anymore
void druid_print_out_of_viscum(void)
{
    printf("Druid: I'm out of viscum. I'm going back to ... zZz\n");
}