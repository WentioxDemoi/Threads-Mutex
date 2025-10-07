#ifndef DRUID_H
#define DRUID_H

#include "includes.h"
int loadSize;

// Prints when the druid thread starts
void druid_print_ready(void);

// Prints when the druid is called to refill the pot
void druid_print_refill(int refill_left);

// Prints when the druid runs out of ingredients
void druid_print_out_of_viscum(void);

#endif // DRUID_H