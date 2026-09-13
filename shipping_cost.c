#include<stdio.h>
#include<stdlib.h>
void main()
{
    float weight,cost,rate=90;
    char destination;

    printf("\nEnter weight in Kg: ");
    scanf("%f",&weight);
    if(weight<=0)
        printf("\nInvalid weight!");
    else
    {
        printf("\n---------------------");
        printf("\npress D for domestic shipping");
        printf("\npress I for International shipping");
        printf("\n---------------------");
        scanf(" %c",&destination);
        if(destination=='D'||destination=='I'||destination=='d'||destination=='i')
        {
            if(weight<=2)
            cost=5;
        else if(weight>2 && weight<=10)
        {
            if(destination =='I'||destination =='i')
                cost = 25;
            else if(destination =='D'||destination =='d')
                cost =10;
        }
        else
        {
            if(destination =='I'||destination =='i')
                cost = 50*rate;
            else if(destination =='d'||destination =='D')
                cost = 20*rate;
        }
        printf("%c",destination);
        printf("\n%f",cost);
    system("cls");
    printf("\nYour parcel weight is %.2fKg",weight);
    if(weight>10)
        {
            printf("\nExchange rate from dollar to rupee is %.2f",rate);
            printf("\nYour total cost is Rs.%.2f",cost);
        }
    else
    {
        printf("\nYour total cost is Rs.%.2f",cost);
    }
        }
        else
        {
            system("cls");
            printf("\nInvalid destination key!");
        }

    }
}
