#include "includes.h"

// Displays the correct program usage to the user
void usage(void)
{
    printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
}

// Checks the values passed as arguments
// Returns 1 if any value is zero or negative, otherwise 0
int nullValue(int ac, char **tab)
{
    int result = 0;
    for (int i = 1; i < ac; i++) {
        long tmp = strtol(tab[i], NULL, 10); // Converts the argument to an integer
        // Checks if the number of villagers exceeds the thread limit
        if (i == 1 && tmp > _NB_THREADS_) {
            printf("Can't have more than %d villagers (Nb of threads)\n", _NB_THREADS_);
            exit(1);
        }
        // Checks if the value is less than or equal to 0
        if (tmp <= 0)
            result++;
    }
    return result;
}

// Program entry point
int main(int ac, char **av)
{
    // Shows help if the user passes -h as an argument
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        exit(0);
    } 
    // Checks the number of arguments
    else if (ac != 5) {
        printf("Not the good number of argument\n");
        usage();
        exit(1);
    } 
    // Checks the validity of the argument values
    else {
        if (nullValue(ac, av) > 0) {
            printf("Values must be > 0\n");
            usage();
            exit(1);
        }
    }
}