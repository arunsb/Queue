#include<stdio.h> 
#include<stdlib.h>

#define MAX 11
struct Node
{
        int value;
        struct Node* next;
}*rear, *front;

int cnt;

int delQueue()
{
     struct Node *temp, *var=rear;

     if(rear)
     {
#ifdef LOG_INFO
         printf("Element removed ====> %d\n",rear->value); 
#endif
         rear = rear->next;
         free(var);
         cnt--;
         return 0;
     }
     else
     { 
  	 front=NULL;
 	 cnt=0;
	 printf("\nDelQue:  Queue Empty !!!!!!!!!!!!!!!!!!!!!!!!!");
         return -1;
     }
}

int pushQueue(int value)
{
     struct Node *temp;
    
     if(cnt == MAX) 
     {
          printf("Queue is Full !!!!!!!!!!!!\n");
          return -1;
     }
    
     temp=(struct Node *)malloc(sizeof(struct Node));
     temp->value=value;
     if (front == NULL)
     {
           front=temp;
           front->next=NULL;
           rear=front;
     }
     else
     {
           front->next=temp;
           front=temp;
           front->next=NULL;
     }
     cnt++;
     return 0;
}

void display()
{
     struct Node *var=rear;
     if(var!=NULL)
     {
           printf("\nQueue Elements list:  ");
           while(var!=NULL)
           {
                printf("\t%d",var->value);
                var=var->next;
           }
           printf("\n");
     } 
     else
           printf("\nDis: Queue is Empty");
}
