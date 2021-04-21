#include <stdlib.h>
typedef int T_list;

typedef struct node {
    struct node *prv, *nxt;
    T_list val;
} node;

node* newnode(T_list x) {
    node *nd = malloc(sizeof *nd);
    nd->val = x; nd->prv = nd->nxt = NULL;
    return nd;
}

void push_front(T_list x, node* *front, node* *back) {
    node *nd = newnode(x);
    if(*front == NULL) *back = nd;
    else (*front)->prv = nd;
    nd->nxt = *front; *front = nd;
}

void push_back(T_list x, node* *front, node* *back) {
    node *nd = newnode(x);
    if(*back == NULL) *front = nd;
    else (*back)->nxt = nd;
    nd->prv = *back; *back = nd;
}

node* pop_front(node* *front, node* *back) {
#ifdef assert
    assert(*front != NULL);
#endif
    node *ret = *front;
    if(ret->nxt == NULL) *back = NULL;
    else ret->nxt->prv = NULL;
    *front = ret->nxt;
    return ret;
}

node* pop_back(node* *front, node* *back) {
 #ifdef assert
   assert(*back != NULL);
#endif
    node *ret = *back;
    if(ret->prv == NULL) *front = NULL;
    else ret->prv->nxt = NULL;
    *back = ret->prv;
    return ret;
}
