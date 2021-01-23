#include<stdio.h>
#include<conio.h>

#define max 10

int adj[max][max];
int n;

int main()
{
    int i,j,origin,destin;
    int type;

    printf("Enter the Number of vertex: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        printf("Enter edge [%d] : ",i);
        scanf("%d %d",&origin,&destin);
        if(origin == -1 && destin == -1)
            break;
        if(origin>n || destin >n || origin<0 || destin<0)
        {
            printf("\nInvalid matrix\n3");
            i--;
        }
        else{
            adj[origin][destin] = 1;
        }

    }

    printf("The Adjacency matrix is: \n");
    for(i=0; i<=n-1; i++)
    {
        for(j=0; j<=n-1; j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }


}
