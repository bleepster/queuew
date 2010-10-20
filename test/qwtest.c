#include "../src/queuew.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _test_dummy
{
    int i;
} TestDummy;

int main(void)
{
    int i, count, ret;
    void *h = NULL;
    TestDummy *td_p = NULL;

    ret = qw_init(&h); 
    if(ret < 0) {
         fprintf(stderr, "ERROR: qw_init()\n");
         return (1);
    }

    count = 0;
    for (i = 0; i < 100; ++i) {
         td_p = (TestDummy *) malloc(sizeof(TestDummy));
         td_p->i = i;
         if(qw_push(h, td_p) < 0)
              fprintf(stderr, "ERROR: qw_push(), index: %d\n", i);
         else
              ++count;
    } 
    fprintf(stdout, "total successful push operations: %d\n", count);

    count = 0;
    for (i = 0; i < 100; ++i) {
         td_p = NULL;
         if(qw_pop(h, (void *)&td_p) < 0 || td_p->i != i)
              fprintf(stderr, "ERROR: qw_pop(), index: %d\n", i);
         else
              ++count;
    } 
    fprintf(stdout, "total successful pop operations: %d\n", count);

    qw_cleanup(h);

    return (0);
}
