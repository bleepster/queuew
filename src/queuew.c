#include "queuew.h"
#include <stdlib.h>


struct qw_node {
    void *d;
    TAILQ_ENTRY(qw_node) entries;
};

typedef struct _qw {
    TAILQ_HEAD(qw_h, qw_node) h;
} QW;


int qw_init(void **handle)
{
    QW *qw_p = (QW *) malloc(sizeof(QW));
    
    TAILQ_INIT(&qw_p->h);
    *handle = (void *)qw_p;

    return (0);
}


int qw_push(void *handle, void *data)
{
    struct qw_node *node = NULL;
    QW *qw_p = (QW *)handle;

    node = (struct qw_node *) malloc(sizeof(struct qw_node));
    node->d = data;
    TAILQ_INSERT_HEAD(&qw_p->h, node, entries);

    return (0);
}


int qw_pop(void *handle, void **data)
{
    struct qw_node *node = NULL;
    QW *qw_p = (QW *)handle;

    *data = NULL;
    if(!TAILQ_EMPTY(&qw_p->h)) {
       node = TAILQ_LAST(&qw_p->h, qw_h);
       *data = node->d;
       TAILQ_REMOVE(&qw_p->h, node, entries);
       free(node);
    }

    return ((*data != NULL) ? 0 : -1);
}


int qw_empty(void *handle)
{
    QW *qw_p = handle;

    return (TAILQ_EMPTY(&qw_p->h));
}


int qw_cleanup(void *handle)
{
     QW *qw_p = handle;

     if(TAILQ_EMPTY(&qw_p->h)) {
         free(qw_p);
         return (0);
     }
     else {
         return (-1);
     }
}
