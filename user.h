//
// Created by iskandar on 10/7/18.
//

#ifndef LAB2_USER_H
#define LAB2_USER_H

typedef struct _user {

    char *uid;          //University ID of team member
    char *firstName;
    char *lastName;
    char *baseLoc;      //Base path of the user, defaults to XBASE/uid
    char *envvar;       //environment variable file

    char *(*pf_get_uid)(struct _user *);
    void (*pf_set_uid)(struct _user *);

    char *(*pf_get_firstname)(struct _user *);
    void (*pf_set_firstname)(struct _user *, char *);

    char *(*pf_get_lastname)(struct _user *);
    void (*pf_set_lastname)(struct _user *, char *);

    char *(*pf_get_baseloc)(struct _user *);
    void (*pf_set_baseloc)(struct _user *, char *);

    char *(*pf_get_envvar)(struct _user *);
    void (*pf_set_envvar)(struct _user *, char *);

    void (*pf_update_envvar)(struct _user *);

} User;

User *init_user();

char *get_uid(User *);
void set_uid(User *);

char *get_firstname(User *);
void set_firstname(User *, char *);

char *get_lastname(User *);
void set_lastname(User *, char *);

char *get_baseloc(User *);
void set_baseloc(User *, char *);

char *get_envvar(User *);
void set_envvar(User *, char *);

void update_envvar(User *);

void destuct(User *);

#endif //LAB2_USER_H


