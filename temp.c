#include<stdio.h>
#include<stdlib.h>

struct arr{
    int data;
    struct arr *next;
};
int main()
{
    int n,x=0,sum=0;
    typedef struct arr node;
    node *head,*tail,*temp;
    printf("Press 1 to enter data\n");
    scanf("%d",&n);
    do
    {  
        if(n==1)
        {
            head=(node*)malloc(sizeof(node));
            scanf("%d",&head->data);
            sum+=head->data;
            x++;
        }
        printf("Press 1 to enter data\n");
        scanf("%d",&n);
    } while (n==1);
    printf("The tota values of %d nodes is %d",x,sum);
    free(head);
    return 0;
}