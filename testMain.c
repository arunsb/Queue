#include <stdio.h>
#include <stdlib.h>

extern struct Node *front,*rear;
extern int cnt;

int main()
{
     int x=0;
     front=NULL;
     rear=NULL;
     cnt=0;

     while(1)
     {
	  printf("\n1. Push to Queue");
	  printf("\n2. Pop from Queue");
	  printf("\n3. Display Data of Queue");
	  printf("\n4. Exit\n");

          printf("\n\n\nChoose Option: ");
          scanf("%d",&x);
          switch(x)
          {
                case 1:
                {
                     static int value=0;
                     int ret=0;
                     //int value=0;
                     //printf("\n   Enter a value to push into Queue: ");
                     //scanf("%d",&value);
                     ret=pushQueue(value); 
                     display();
                     if(ret==0)
                         value++;
                     break;
                }
                case 2:
                {
                     delQueue();
                     display();
                     break;
                }
                case 3:
                {
                     display();
                     break;
                }
                case 4:
                {
                     exit(0);
                }
                default:
                {
                     printf("\nwrong choice for operation");
                     break;
                }
          }
     }
}
