#include <stdlib.h>
typedef int T_list;

typedef struct node {
    T_list val;
    struct node *nxt;
} node;

typedef struct list {
    node *front, *back;
} list;

list newlist() {
    list res = {NULL, NULL};
    return res;
}

node* newnode(T_list x) {
    node *nd = malloc(sizeof *nd);
    nd->val = x; nd->nxt = NULL;
    return nd;
}

void push_front(list *ls, T_list x) {
    node *nd = newnode(x);
    if(ls->front == NULL) ls->back = nd;
    nd->nxt = ls->front; ls->front = nd;
}

void push_back(list *ls, T_list x) {
    node *nd = newnode(x);
    if(ls->back == NULL) ls->front = nd;
    else ls->back->nxt = nd;
    ls->back = nd;
}

node* pop_front(list *ls) {
#ifdef assert
    assert(ls->front != NULL && "pop empty list");
#endif
    node *ret = ls->front;
    if(ret->nxt == NULL) ls->back = NULL;
    ls->front = ret->nxt;
    return ret;
}
