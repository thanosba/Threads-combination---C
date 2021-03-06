#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "pthread.h"

void * process(void * arg)
{
    int i;
    fprint(stderr, "Start the thread %s\n", (char*)arg);
    for(i=0;i<10;i++){
        write(1, (char*)arg, 1);
    }
    return NULL;
}
int main()
{
    int retcode;
    pthread_t th_a, th_b;
    void * retval;
    retcode = pthread_create(&th_a, NULL, process, "a");
    if (retcode !=0)fprintf(stderr, "create a failed%d\n"retcode);
    retcode = pthread_create(&th_b, NULL, process, "b");
    if (retcode !=0)fprintf(stderr, "create b failed%d\n"retcode);
    retcode = pthread_join(th_a, &retval);
    if (retcode !=0)fprintf(stderr, "join a failed%d\n"retcode);
    retcode = pthread_join(th_b, &retval);
    if (retcode !=0)fprintf(stderr, "join b failed%d\n"retcode);
    return 0;   
 }
