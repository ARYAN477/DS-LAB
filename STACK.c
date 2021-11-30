#include<stdio.h>
#define MAX 5
int st[MAX], top= -1;
void push( int st[], int val);
int pop( int st[]);
int peek( int st[]);
void display( int st[]);
int isempty();
int isfull();
int main() {
    int val, option;
    do{
        printf("MAIN MENU : \n");
        printf("1. PUSH 2. POP 3. PEEK 4. DISPLAY 5. EXIT");
        printf("\n ENTER YOUR OPTION: ");
        scanf("%d",&option);
        switch(option) {
            case 1:
            printf("\n Enter number to be pushed: ");
            scanf("%d",&val);
            push (st,val);
            break;
            
            case 2:
            val=pop(st);
            if(val!=-1)
            { printf("\n VALUE POPPED OUT IS %d\n",val);}
            break;
            
            case 3:
            val=peek(st);
            if(val!=-1)
            printf("\n VALUE ON TOP OF STACK IS %d\n",val);
            break;
            
            case 4:
            display(st);
            break;
            
            case 5:
            printf("\n PROGRAM ENDED! \n");
            break;
            default:
            printf("INVALID INPUT...TRY AGAIN");
            break;
        }
    } while (option!=5);
    return 0;
}
int isempty() {
    if(top== -1) { return 1;}
    else { return 0;}
}

int isfull() {
    if(top==MAX-1) { return 1;}
    else { return 0;}
}

void push ( int st[], int val) {
    if(isfull()) { printf("STACK OVERFLOW");}
    else {st[++top]=val;}
    }
int pop(int st[]) {
    if(isempty()) {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else { return st[top--];}
}
int peek( int st[]) {
    if(top== -1) { printf("STACK IS EMPTY");
    return -1;}
    else { return st[top];}
}

void display(int st[]) {
    if(isempty()) { printf(" \n STACK IS EMPTY");}
    else {
        for( int i=top; i>=0;i--) {
            printf("\n %d",st[i]);
            printf("\n");
        }
    }
}