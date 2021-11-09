#include<stdio.h>
#include<conio.h>
#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void
display ()
{
  int i;
  if (front == -1)
    {
      printf ("QUEUE IS EMPTY\n");
    }
  else
    {
      printf ("QUEUE is: \n");
      for (i = front; i <= rear; i++)
	{
	  printf ("%d \n", queue_array[i]);
	}
    }
}

void
insert ()
{
  int add_item;
  if (rear == MAX - 1)
    {
      printf ("QUEUE OVERFLOW\n");
    }
  else
    {
      if (front == -1)
	{
	  front = 0;
	  printf ("INSERT ELEMENT IN QUEUE: ");
	  scanf ("%d", &add_item);
	  rear = rear + 1;
	  queue_array[rear] = add_item;
	}
    }
}

void
delete ()
{
  if (front == -1 || front > rear)
    {
      printf ("QUEUE OVERFLOW\n");
      return;
    }
  else
    {
      printf ("DELETED ELEMENT IS: %d", queue_array[front]);
      front = front + 1;

    }
}


void
main ()
{
  int choice;
  while (1)
    {
      printf ("1.Insert \n");
      printf ("2.Delete \n");
      printf ("3.Display \n");
      printf ("4.Exit \n");
      printf ("Enter your choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  insert ();
	  break;
	case 2:
	  delete ();
	case 3:
	  display ();
	  break;
	case 4:
	  exit (1);
	default:
	  printf ("Invalid choice\n");
	}
    }
}
