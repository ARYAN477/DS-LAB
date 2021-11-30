#include <stdio.h>
#include <stdlib.h>

int A[5];
int front = -1, rear = -1;

/* Function to insert value into priority queue */
void insert_by_priority(int data)
{
    if(rear >= 4)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    else
    {
          if((front == -1) && (rear == -1))
          {
             front = front + 1;
             rear = rear + 1;
             A[rear] = data;
             return;
          }    
          else
          {
             check(data);
          }
          rear = rear + 1;
    }
}
 
/* Function to check priority and place element */
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= A[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                A[j] = A[j - 1];
            }
            A[i] = data;
            return;
        }
    }
    A[i] = data;
}
 
/* Function to delete an element from queue */
void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    else
    {
        for (i = 0; i <= rear; i++)
        {
            if (data == A[i])
            {
                for (; i < rear; i++)
                {
                    A[i] = A[i + 1];
                }
                rear = rear - 1;
                if (rear == -1)
                { 
                    front = -1;
                }
                return;
            }
        }
        printf("\n%d not found in queue to delete", data);
    }
}
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d ", A[front]);
    }
    front = 0;
}
 
int main()
{
    int value,choice;
 
    printf("1-Insert an element into queue");
    printf("\n2-Delete an element from queue");
    printf("\n3-Display queue elements");
    printf("\n4-Exit");
 
    while (choice != 4)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);
 
        switch(choice)
        {
           case 1: 
                   printf("\nEnter value to be inserted : ");
                   scanf("%d",&value);
                   insert_by_priority(value);
                   break;
           case 2:
                   printf("\nEnter value to delete : ");
                   scanf("%d",&value);
                   delete_by_priority(value);
                   break;
           case 3: 
                   display_pqueue();
                   break;
           case 4: 
                   exit(0);
           default: 
                   printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
    
    return 0;
}