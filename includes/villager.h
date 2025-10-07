#ifndef VILLAGER_H
#define VILLAGER_H

#include "includes.h"


int loads;

// Prints when a villager thread starts
void villager_print_start(int id);

// Prints when a villager tries to drink some potion
void villager_print_need_drink(int id);

// Prints when a villager calls the druid for a refill
void villager_print_call_druid(int id, int *needRefill, int refill_left);

// Prints when a villager is fighting
void villager_print_fight(int id, int *fights_left);

// Prints when a villager has done all his fights
void villager_print_sleep(int id);

#endif // VILLAGER_H