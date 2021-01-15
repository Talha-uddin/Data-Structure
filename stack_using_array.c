#include<stdio.h>
#include<conio.h>

#define SIZE 10

void push(int);
void pop();
void display();

int array[SIZE],top = -1;

int main()
{
    int choice,value;
    printf(":::Stack Using Array:::\n");
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: printf("Enter the value you want to insert: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("Wrong selection!!!try again...\n");
        }
    }

}

void push(int value)
{
    if(top == SIZE - 1)
        printf("Stack is Full!!!\n");
    else{
        top++;
        array[top] = value;
        printf("Insertion Successful!!!\n");
    }
}

void pop()
{
    if(top == -1)
        printf("Stack is Empty!!!\n");
    else{
        printf("Deleted element: %d",array[top]);
        top--;
    }
}

void display()
{
    int i;
    if(top == -1)
        printf("Stack is Empty!!!\n");
    else{
        printf("Elements are: ");
        for(i=top; i>=0; i--)
        {
            printf("%d/t",array[i]);
        }
    }
}