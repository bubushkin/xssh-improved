//
// Created by iskandar on 10/8/18.
//

#ifndef LAB2_ENVVAR_H
#define LAB2_ENVVAR_H

#include "utils.h"

/*
 * We are storing environment variables in a LinkedList
 *
 */

typedef  LinkedList Environment;

Environment *init_env();
void free_env(Environment *);

typedef struct _envvar {
    char *var;
    char *value;
} EnvVar;


void export(Environment **, char *, char *);

void unexport(Environment **, char *);


#endif //LAB2_ENVVAR_H