#include <stdio.h>
#include <stdlib.h>
#include "team.h"
#include "const.h"
#include "user.h"

int main(int argc, char **argv){

    Team *p_team = init_team();
    p_team->pf_initialize(&p_team->pnode, init_user("Iskandar Askarov", "ia253"));
    p_team->pf_insert(&p_team->pnode, init_user("Root Root", "root"));
    User *p_user = p_team->pnode->p_next->element;



    release_list_obj(p_team);

    return EXIT_SUCCESS;
}
