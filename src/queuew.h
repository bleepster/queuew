#ifndef __QUEUEW_H
#define __QUEUEW_H

#include <sys/queue.h>

int qw_init(void **handle);
int qw_empty(void *handle);
int qw_push(void *handle, void *data);
int qw_pop(void *handle, void **data);
int qw_cleanup(void *handle);

#endif
