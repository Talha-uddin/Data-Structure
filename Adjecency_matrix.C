#include<stdio.h>
#include<conio.h>

#define max 20

int adj[max][max];
int n;

int main()
{
    int choice;
    int node,origin,destin;
    //graph();
    while(1)
    {
        printf("1.Insert\n2.delete\n3.display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertNode();
            break;
            case 2: printf("Enter a node to be deleted: ");
            scanf("%d",&node);
            deleteNode(node);
            break;
            case 3: 
                display();
                break;
            case 4: exit(0);

            default: printf("Wrong Selection!!!try again...");
        }
    }
}


