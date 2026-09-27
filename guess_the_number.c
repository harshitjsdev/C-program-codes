#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int number, count = 0, value = 786;
    do
    {
        printf("\nEnter a lucky Number:");
        scanf("%d",&number);
        if(number<0)
            {
                printf("\nenter valid number!");
            }
        else if(number==value)
        {
            count++;
            printf("\nCorrect value!");
            break;
        }
        else if(number>value)
        {
            count++;
            printf("\nToo High");
        }
        else
            {
                count++;
                printf("\nToo Low");
            }

    } while(number!=value);
    printf("\npress any key to see result");
    getch();
    system("cls");
    printf("\nYou took %d chances",count);
}
