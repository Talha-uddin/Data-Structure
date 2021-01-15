#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear = NULL;

void Insert(int);
void Delete();
void display();

int main()
{
    int choice,value;
    printf(":::Queue using Linked List:::\n");
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value you want to insert: ");
                    scanf("%d",&value);
                    Insert(value);
                    break;
            case 2: Delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Wrong Selection!!!try again...\n");
        }
    }
}

void Insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
    printf("Insertion Successful!!!\n\n");
}

void Delete()
{
    if(front == NULL)
        printf("\nQueue is Empty!!!\n");
    else{
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted Element: %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    if(front == NULL)
        printf("\nQueue is Empty!!!\n");
    else{
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d--->",temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n",temp->data);
    }
}