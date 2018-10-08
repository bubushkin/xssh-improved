//
// Created by iskandar on 10/7/18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user.h"
#include "const.h"


char *get_uid(User *pauser){
    return pauser->uid;
}

void set_uid(User *pauser, char *username){
    if(strlen(username) > 0x0){
        strcpy(pauser->uid, username);
    }
}

char *get_name(User *pauser){
    pauser->name;
}

void set_name(User *pauser, char *fname){
    if(strlen(fname) >= 0x0){
        strcpy(pauser->name, fname);
    }
}

char *get_basepath(User *pauser){
    pauser->basepath;
}

void set_basepath(User *pauser, char *base){
    if(strlen(base) >= 0x0){
        char *temp = (char *)malloc(sizeof(char) * MAX_BUFF);
        strcpy(temp, base);
        strcpy(pauser->basepath, strcat(temp, pauser->uid));
        free(temp);
    }
}

char *get_envvar(User *pauser){
    pauser->envvar;
}

void set_envvar(User *pauser, char *env){
    if(strlen(env) >= 0x0){
        strcpy(pauser->envvar, env);
    }
}

void release_user_obj(User *pauser){

    free(pauser->uid);
    free(pauser->name);
    free(pauser->envvar);
    free(pauser->basepath);
    free(pauser);

}

User *init_user(char *fname, char *lname){

    User *p_user = NULL;

    p_user = (User *)calloc(0x1, sizeof(User));

    p_user->uid = (char *)calloc(strlen(lname), sizeof(char));
    p_user->name = (char *)calloc(strlen(fname), sizeof(char));
    p_user->envvar = (char *)calloc(0x7, sizeof(char));
    p_user->basepath = (char *)calloc(PATH_MAX_LEN, sizeof(char));
    strcpy(p_user->envvar, "var.env");
    strcpy(p_user->name, fname);
    strcpy(p_user->uid, lname);

    p_user->pf_get_uid = get_uid;
    p_user->pf_set_uid = set_uid;

    p_user->pf_get_name = get_name;
    p_user->pf_set_name = set_name;

    p_user->pf_get_basepath = get_basepath;
    p_user->pf_set_basepath = set_basepath;

    p_user->pf_get_envvar = get_envvar;
    p_user->pf_set_envvar = set_envvar;

    p_user->pf_set_basepath(p_user, "/home/iskandar/CLionProjects/xssh/opt/xssh/");

    return p_user;
}