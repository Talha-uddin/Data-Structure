#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void InsertAtbeginning(int);
void InsertAtend(int);
void InsertBetween(int,int,int)
void Display();
void removeAtbeginning();
void removeAtend();
void removeSpecific(int);

int main()
{
    int choice,value,choice1,loc1,loc2;
    clrsrc();
    printf(":::::::MENU:::::::\n");
    while(1){
    
    mainMenu:  printf("1.Insert\n2.Display\n3.Delete\n4.Exit\nEnter your choice:");
                scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the value you want to insert: ");
                scanf("%d",&value);
                while(1){
                        printf("Where do you want to insert: \n");
                        printf("1.AT Beginning\n2.AT End\n3.Between\nEnter your choice: ");
                        scanf("%d",&choice1);
                    switch(choice1)
                    {
                        case 1: InsertAtbeginning(value);
                        break;
                        case 2: InsertAtend(value);
                        break;
                        case 3: printf("Enter the two value where you want to insert: ");
                                scanf("%d %d",&loc1,&loc2);
                                InsertBetween(value,loc1,loc2);
                                break;
                            
                        default: printf("Wrong Input!!!try again..\n\n");
                                 goto mainMenu;
                    }
                    goto subMenuEnd;
                }
                subMenuEnd:
                break;
        case 2: Display();
                break;

        case 3: printf("How do you want to delete: \n1.from Beginning\n2.From End\n3.From Specific\nEnter your choice: ");
                scanf("%d",&choice1);

                switch(choice1)
                {
                    case 1: removeAtbeginning();
                    break;
                    case 2: removeAtend();
                    break;
                    case 3: printf("Enter the value which you want to delete: ");
                            scanf("%d",&loc2);
                            removeSpecific(loc2);
                            break;
                        
                    default: printf("Wrong Input!!!try again...\n\n");
                    goto mainMenu;
                }
                break;
        case 4: exit(0);
        default: printf("Wrong selection!!!try again...\n\n");
    }
    }
}

void InsertAtbeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    printf("One Node Inserted!!!\n\n");
}

void InsertAtend(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("One Node Inserted!!!\n\n");
}

void InsertBetween(int value,int loc1,int loc2)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->data != loc1 && temp->data != loc2)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("One Node Inserted!!/n/n");
}

void removeAtbeginning()
{
    if(head == NULL)
    {
        printf("list is Empty!!/n");
    }
    else{
        struct Node *temp = head;
        if(head->next = NULL)
        {
            head = NULL;
            free(temp);
        }
        else{
            head = temp->next;
            free(temp);
            printf("One Node deleted!!!\n");
        }
    }
}

void removeAtend()
{
    if(head == NULL)
    {
        printf("List is Empty!!!\n");
    }
    else{
        struct Node *temp = head,*temp1;
        if(head->next == NULL)
        {
            head = NULL;
        }
        else{
            while(temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
        }
        free(temp);
        printf("One Node Deleted!!!\n");
    }
}

void removeSpecific(int delValue)
{
    struct Node *temp = head,*temp1;
    while(temp->data != delValue)
    {
        if(temp->next == NULL){
            printf("Given Node is Not found in this list!!!\n");
            goto functionEnd;
        }
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    free(temp);
    printf("One Node Deleted!!!\n");
    functionEnd:
}

void Display()
{
    if(head == NULL)
    {
        printf("List is Empty!!\n");
    }
    else{
        struct Node *temp = head;
        printf("list element are - \n");
        while(temp->next != NULL)
        {
            printf("%d--->",temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL",temp->data);
    }
}