/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>

#define MAX 3
int queue_array[MAX];

int rear = -1;
int front = -1;
int set=1;

main()
{
    int choice;
    while (1)
    {
        printf("\n\n");
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("DBG front = %d  rear= %d\n",front, rear);
            insert();
            break;
            case 2:
            printf("DBG front = %d  rear= %d\n",front, rear);
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            return(1);

            default:
            printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
} /*End of main()*/


insert()
{
    int add_item;

   
    if(set)
    {
        if (rear < front)
        {
            printf("Set  Queue is FULL                 ------>>>> !!!!!!\n");
            return;
        }
    }
    else
    {
        if (rear >= front)
        {
            printf("unSet  Queue is FULL                 ------>>>> !!!!!!\n");
            return;
        }
    }

    rear = rear + 1;
    if (rear >= MAX)
    {
       rear=0;
       set=0;
    }

    printf("Inset the element in queue ( %d ) : ",rear);
    scanf("%d", &add_item);
    queue_array[rear] = add_item;

#if 0
    if(set)
    {
        if (rear > (front))
        {
             printf("Inset the element in queue ( %d ) : ",rear);
             scanf("%d", &add_item);
             queue_array[rear] = add_item;
        }
        else
        {
            printf("Set  Queue is FULL                 ------>>>> !!!!!!\n");
            return;
        }
    }
    else
    {
        if (rear < (front))
        {
             printf("Inset the element in queue : ");
             scanf("%d", &add_item);
             queue_array[rear] = add_item;
        }
        else
        {
            printf("unSet  Queue is FULL                 ------>>>> !!!!!!\n");
            return;
        }
    }
#endif

} /*End of insert()*/


delete()
{
#if 0
    static int first=1;
    if(first)
    {
      first=0;
      front++;
    }
#endif


    if(!set)
    {
        if (front < rear)
        {
            printf("unSet Queue is Empty !!!!!!\n");
            return;
        }
    }
    else
    {
        if (front > rear)
        {
            printf("Set  Queue is Empty !!!!!!\n");
            return;
        }
    }

    front = front + 1;
    if (front == MAX)
    {
       front=0;
       set=1;
    }

    printf("Deleted elem ====> %d,    ind=%d\n",queue_array[front],front);


#if 0
    if(!set)
    {
        if (front >= (rear))
        {
             printf("Deleted elem ====> %d,    ind=%d\n",queue_array[front],front);
        }
        else
        {
            printf("unSet Queue is Empty !!!!!!\n");
            return;
        }
    }
    else
    {
        if (front <= (rear) )
        {
             printf("Deleted elem ====> %d,    ind=%d\n",queue_array[front],front);
        }
        else
        {
            printf("Set  Queue is Empty !!!!!!\n");
            return;
        }
    }
#endif

} /*End of delete() */


display()
{
    int i;
    int start;
    if (front == rear)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        if (set)
        {
            if(front == -1 ) start=0;
            else             start=front;
            for (i = start; i <= (rear); i++)
                printf("%d ", queue_array[i]);
        }
        else
        {
            if(front == -1 ) start=0;
            else             start=front;

            for (i = start; i < MAX; i++)
                printf("%d ", queue_array[i]);
	    for (i = 0; i <= front; i++)
                printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
} /*End of display() */
