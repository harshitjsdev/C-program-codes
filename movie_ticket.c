#include<stdio.h>
#include<stdlib.h>
void main()
{
    int age,price;
    printf("\nEnter your Age: ");
    scanf("%d",&age);
    if(age<0)
        printf("\nInvalid age! try again");
    else
    {
        if(age>5)
        {
            if(age>17)
            {
                if(age>64)
                    price=100;
                else
                    price=200;
            }
            else
                price=150;
        }
        else
            price= 0;
        system("cls");
        printf("Your age is %d\nYou have to pay Rs.%d",age,price);
    }

}
