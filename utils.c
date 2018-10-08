//
// Created by iskandar on 10/7/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "utils.h"
#include "const.h"

/*
 * Traverse through the list counting nodes in the list and return the final count.
 */
unsigned int get_size(LinkedList *palist){

    Node *paux = palist->pnode;

    if(paux != NULL){
        palist->size++;
        paux = paux->p_next;
    }else{
        return 0x0;
    }

    return palist->size;
}

/*
 * Deletes the element from the list, assuming our offset is correct :P
 */
void delete(Node **pastart, unsigned int aoffset){

    int offset = 0x0;
    Node *aux = *pastart;
    while(aux != NULL){
        if(offset == aoffset){
            Node *ptemp = aux->p_next;
            aux->p_next = ptemp->p_next;
            ptemp->p_next = NULL;
            free(ptemp);
            break;
        }
        offset++;
        aux = aux->p_next;
    }
}

/*
 * Inserts the element at the end of the list
 */
void insert(Node **start, void *pVoid){

    Node *paux = *start;
    while(paux->p_next != NULL){
        paux = paux->p_next;
    }
    Node *pend = (Node *) calloc(0x1, sizeof(Node *));
    if(pend != NULL){
        pend->element = pVoid;
        pend->p_next = NULL;
        paux->p_next = pend;
    } else{
        PRINT_ERR("Memory allocation failed");
    }

}

/*
 * Searches for given elements *pVoid and returns the offset of the element;
 */
int search(Node **pastart, void *pVoid, void *pVoidAddr){

    Node *aux = *pastart;
    int offset = 0x0;
    while(aux != NULL){
        if(aux->element == pVoid){
            memcpy(pVoidAddr, &aux->element, 0x1);
            return offset;
        }
        aux = aux->p_next;
        offset++;
    }
    return offset;
}

/*
 * Constructor
 */
void *init_list(){

    LinkedList *p_linkedList = NULL;
    p_linkedList = malloc(sizeof(LinkedList));
    p_linkedList->size = 0x0;
    p_linkedList->pf_get_size = get_size;
    p_linkedList->pf_insert = insert;
    p_linkedList->pf_delete = delete;
    p_linkedList->pf_search = search;
    p_linkedList->pf_initialize = init_node;

    return p_linkedList;
}

void init_node(Node **pnode, void *pVoid){

    *pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL){
        PRINT_ERR("Memory allocation failed");
    }
    (*pnode)->element = pVoid;
    (*pnode)->p_next = NULL;

}

/*
 * Destructor
 */
void release_list_obj(LinkedList *palist){

    LinkedList *aux;

    palist->pf_initialize = NULL;
    palist->pf_insert = NULL;
    palist->pf_get_size = NULL;
    palist->pf_search = NULL;
    palist->pf_delete = NULL;
    palist->pf_get_size = NULL;

    while(palist->pnode != NULL){
        aux = palist;
        palist->pnode = palist->pnode->p_next;
        free(aux);
    }
}
