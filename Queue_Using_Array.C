#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void Insert(int);
void Delete();
void Display();

int main()
{
    int choice,value;
    printf(":::Queue Using Array:::\n");
    while(1)
    {
        printf("\n1.enQueu\n2.deQueue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value you want to Insert: ");
                    scanf("%d",&value);
                    Insert(value);
                    break;
            case 2: Delete();
                    break;
            case 3: Display();
                    break;
            case 4: exit(0);

            default: printf("Wrong selection!!!try agian...\n");
        }
    }
}

void Insert(int value)
{
    if(rear == SIZE - 1)
        printf("Queue is full!!!\n");
    else{
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Insertion Successful!!!");
    }
}

void Delete()
{
    if(front == rear)
        printf("Queue is Empty!!!");
    else{
        printf("\nDeleted Element: %d",queue[front]);
        front++;
        if(front == rear)
            front = rear = -1;
    }
}

void Display()
{ 
    int i;
    if(rear == -1)
        printf("Queue is Empty!!!\n");
    else{
        printf("Element Are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t",queue[i]);
    }
}