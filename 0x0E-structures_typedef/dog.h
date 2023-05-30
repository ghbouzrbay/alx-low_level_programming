#ifndef _HEADER_
#define _HEADER_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/************STRUCTURES***********/

/**
 *struct dog - Dog attributes
 *
 *@name: The name of the dog
 *@age: The age of the dog
 *@owner: The owner of th dog
 *
 *Description: The attributes of the dog
 */

struct dog
{

char *name;
float age;
char *owner;
};

/**
 * dog_t - Typedef for dog structure
 */
typedef struct dog dog_t;



/************FUNCTIONS*************/

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
