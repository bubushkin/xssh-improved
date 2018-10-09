//
// Created by iskandar on 10/7/18.
//

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "const.h"
#include "team.h"
#include "user.h"

/*
 * Reads team.conf file line by line and creates team member data structure - linkedlist
 * Content of the file is following
 * Full Name : username
 */
int __create_team(Team *p_team, char *confPath){

    FILE *fp;
    char *buffer  = malloc(sizeof(char) * MAX_BUFF);
    memset(buffer, 0x0, sizeof(buffer));
    size_t len = 0x0;
    ssize_t read;
    char *member[2];

    PRINT_INFO("Initalizing team members data structure.");

    fp = fopen(confPath, "r");
    PRINT_INFO("Opening %s configuration file..", confPath);
    if(fp == NULL){
        PRINT_ERR("Unable to open team conf file");
        return -0x1;
    }

    while ((read = getline(&buffer, &len, fp)) != -1) {
        char *token = strtok(buffer, ":");

        member[0x0] = (char *)calloc(strlen(token), sizeof(char));
        member[0x1] = (char *)calloc(strlen(token), sizeof(char));

        strcpy(member[0], token);

        while(token != NULL){
            token = strtok(NULL, ":");
            strcpy(member[1], token);
            break;
        }
        p_team->pf_insert(&p_team->pnode, init_user(member[0x0], member[0x1]));
        free(member[0x0]);
        free(member[0x1]);
        memset(buffer, 0x0, sizeof(buffer));
    }

    fclose(fp);
    free(buffer);

}