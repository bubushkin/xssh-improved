//
// Created by iskandar on 10/7/18.
//

#ifndef LAB2_USER_H
#define LAB2_USER_H

typedef struct _user {

    char *uid;          //University ID of team member
    char *name;
    char *basepath;      //Base path of the user, defaults to XBASE/uid
    char *envvar;       //environment variable file

    char *(*pf_get_uid)(struct _user *);
    void (*pf_set_uid)(struct _user *, char *);

    char *(*pf_get_name)(struct _user *);
    void (*pf_set_name)(struct _user *, char *);

    char *(*pf_get_basepath)(struct _user *);
    void (*pf_set_basepath)(struct _user *, char *);

    char *(*pf_get_envvar)(struct _user *);
    void (*pf_set_envvar)(struct _user *, char *);

} User;

User *init_user(char *, char *);

char *get_uid(User *);
void set_uid(User *, char *);

char *get_name(User *);
void set_name(User *, char *);

char *get_lastname(User *);
void set_lastname(User *, char *);

char *get_basepath(User *);
void set_basepath(User *, char *);

char *get_envvar(User *);
void set_envvar(User *, char *);

void release_user_obj(User *);

#endif //LAB2_USER_H