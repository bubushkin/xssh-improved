//
// Created by iskandar on 10/7/18.
//

#ifndef LAB2_UTILS_H
#define LAB2_UTILS_H

/*LinkedList datastructure that will be used in xssh to store users and environment vars*/
typedef struct _node{

    void *element;
    struct _node *p_next;

} Node;

typedef struct _LinkedList{

    Node *pnode;
    unsigned int size;
    void (*pf_initialize)(Node **, void *);
    void (*pf_insert)(Node **, void *);
    unsigned int (*pf_get_size)(struct _LinkedList *);
    void (*pf_delete)(Node **, unsigned int);
    int (*pf_search)(Node **, void *, void *);

} LinkedList;

void *init_list();

unsigned int get_size(struct _LinkedList *);

void release_list_obj(LinkedList *);

void init_node(Node **, void *);
void insert(Node **, void *);
int search(Node **, void *, void *);
void delete(Node **, unsigned int);

/*end of LinkedList interfaces */



#endif //LAB2_UTILS_H
