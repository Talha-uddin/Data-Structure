#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void inorder(struct Node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("  %d",root->data);
        inorder(root->right);
    }
}

int main()
{
    int n,i;
    struct Node *p , *q , *root;
    printf("Enter the number of node to be insert: ");
    scanf("%d",&n);

    printf("\nPlease Enter the numbers to be insert: ");
    for(i=0; i<n; i++)
    {
        p = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->left = NULL;
        p->right = NULL;
        if(i == 0)
        {
            root = p;
        }
        else{
            q = root;

            while(1)
            {
                if(p->data > q->data)
                {
                    if(q->right == NULL)
                    {
                        q->right = p;
                        break;
                    }
                    else
                    {
                        if(q->left == NULL)
                        {
                            q->right = p;
                            break;
                        }
                        else{
                            q = q->left;
                        }
                    }
                }
            }
        }
    }

    printf("\nBinary Search tree nodes in Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}