//
// Created by iskandar on 10/8/18.
//

#include "envvar.h"

Environment *init_env(){
    return (Environment *)init_list();
}

void free_env(Environment *p_env){
    release_list_obj(p_env);
}