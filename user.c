//
// Created by iskandar on 10/7/18.
//

#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "const.h"

User *init_user(){

    User *p_user = NULL;

    p_user = (User *)calloc(0x1, sizeof(User));

    p_user->uid = (char *)calloc(MAX_BUFF, sizeof(char));
    p_user->firstName = (char *)calloc(MAX_BUFF, sizeof(char));
    p_user->lastName = (char *)calloc(MAX_BUFF, sizeof(char));
    p_user->envvar = (char *)calloc(0x7, sizeof(char));
    p_user->baseLoc = (char *)calloc(PATH_MAX_LEN, sizeof(char));
    strcpy(p_user->envvar, "var.env");

}

