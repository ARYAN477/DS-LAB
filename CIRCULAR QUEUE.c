#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 4
int circularq[SIZE];
int rear= -1;
int front= -1;
bool isfull() {
if((rear+1)%SIZE == front) { return true;}
else { return false;}
}
bool isempty() {
if( front== -1) { return true;}
else { return false;}
}
void enque(int value) {
if(isfull()) { printf("QUEUE IS FULL\n");}
else if(isempty()) { front=0; rear=0; circularq[rear]=value;}
else { rear=(rear+1)%SIZE;}
}
void deque() {
if(isempty()) { printf("QUEUE IS EMPTY");}
else if (rear==front) { front=-1;rear=-1;}
else { front=(front+1)%SIZE;}
}
int main() {
int choice, num, i;
printf("\n CIRCULAR QUEUE\n");
while(1) {
printf("1. INSERT 2. DELETE 3. DISPLAY 4. EXIT \n");
printf("ENTER CHOICE: \n");
scanf("%d",&choice);
switch(choice) {
case 1:
printf("ENTER ELEMENT TO BE INSERTED: \n");
scanf("%d",&num);
enque(num);
break;

case 2:
deque();
break;

case 3:
printf("ELEMENTS OF QUEUE ARE : \n");
for(i=front;i!=rear;i=(i++)/SIZE)
{ printf("%d", circularq[i]);}
printf("%d", circularq[rear]);
break;

case 4:
exit(0);

default: printf("INVALID CHOICE");
break;
}
}
}