//
// Created by iskandar on 10/7/18.
//

#include <stdlib.h>
#include "team.h"
#include "utils.h"

/*
 * Team object constructor
 */
Team *init_team(){
    return (Team *)init_list();
}

/*
 * Object destructor
 */
void destructor(Team *palist){
    release_list_obj(palist);
}



