//
// Created by iskandar on 10/8/18.
//

#include "envvar.h"

Environment *init_env_list(){
    return (Environment *)init_list();
}

void free_env_list(Environment *p_env){
    release_list_obj(p_env);
}


void init_default_var(Environment **, char *pname, char *pval){

}

