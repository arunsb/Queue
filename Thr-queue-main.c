
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define READ_MAX_THR  4
#define WRITE_MAX_THR 4
#define MAX_COUNTER   1000

#define LOG printf

pthread_t tRd_id[READ_MAX_THR];
pthread_t tWr_id[WRITE_MAX_THR];
pthread_spinlock_t lock;

volatile int counter=0;
unsigned long thr_loop[READ_MAX_THR + WRITE_MAX_THR ];

extern int delQueue(void);
extern int pushQueue(int);

void* readThr(void *arg)
{
    unsigned long i = 0;
    long my_id = (long)arg;
    int get_val=0;
    unsigned long loop_cnt=0;
    int ret;

    while(1)
    {
             if(counter >= MAX_COUNTER)
   	          break;

	     pthread_spin_lock(&lock);
             loop_cnt++;
             ret=delQueue(); 
             if(ret == -1) { pthread_spin_unlock(&lock); break; }
             display();
	     pthread_spin_unlock(&lock);

	     for(i=0; i<(0xFFFFFF); i++);
    }
    thr_loop[my_id] = loop_cnt;
    return NULL;
}

int value=0;
void *writeThr(void *arg)
{
    int i;
    long my_id = (long)arg;
    unsigned long loop_cnt=0;
    int ret;
    
    while(1)
    { 
            if(counter >= MAX_COUNTER)
                 break;

	    pthread_spin_lock(&lock);
	    counter++;
            loop_cnt++;    
            printf("\n\n\n$$$$$$$$$$$$$$$$$\n");
                     ret=pushQueue(value);
                     if(ret == -1) { pthread_spin_unlock(&lock); break; }
                     value++;
                     display();
            printf("\n$$$$$$$$$$$$$$$$$\n\n\n\n");
	    pthread_spin_unlock(&lock);

            for(i=0; i<(0xFFFFFF); i++);
    }
    thr_loop[my_id] = loop_cnt;
    return NULL;
}



int main(void)
{
    int i = 0;
    int err;

    if( pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE) )
    {
        printf("Mutex init failed :[%s]\n", strerror(err));
        return -1;
    }

    while(i < (int)READ_MAX_THR)
    {
        err = pthread_create(&(tRd_id[i]), NULL, &readThr, (void *)i);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));

        i++;
    }

    i = 0;
    while(i < (int)WRITE_MAX_THR)
    {
        err = pthread_create(&(tWr_id[i]), NULL, &writeThr, ((void *)i+(int)READ_MAX_THR) );
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));

        i++;
    }

    i = 0;
    while(i < (int)READ_MAX_THR)
    {
        pthread_join(tRd_id[i], NULL);
        i++;
    } 

    i = 0;
    while(i < (int)WRITE_MAX_THR)
    {
        pthread_join(tWr_id[i], NULL);
        i++;
    }
    
    i=0;
    while(i < ( (int)READ_MAX_THR + (int)WRITE_MAX_THR ))
    {
        LOG("\nNumber of timees thread lock aquired  for thread %2d,   %4ld\n",i, thr_loop[i]);
        i++;
    }
    
    pthread_spin_destroy(&lock);
    return 0;
}
