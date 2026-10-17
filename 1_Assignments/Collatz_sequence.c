#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,num,res;
    printf("Enter a number: ");
    scanf("%d",&num);
    system("cls");
    if(num<0)
        printf("\nInvalid number");
    else
        {
            res = num;
            printf("\nCollatz sequence: %d",num);
            while(res!=1)
            {
                if(res%2==0)
                    res = res/2;
                else
                    res = (res*3)+1;
                printf(" %d",res);
            }
        }
}
