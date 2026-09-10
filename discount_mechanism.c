#include<stdio.h>
int main()
{
    /*E commerce smart checkout discount Mechanism :
    Input: Total Purchase Amount, Is VIP member(yes/No)
    Processing:
    1. if amount is above Rs.2000 they get 20%discount regardless of member status.
    2. if amount is between(1000-2000),VIP=15%discount ,Non VIP=10% discount.
    3. if amount is less than Rs.1000, VIP =05%discount, Non VIP = no discount. */

    float discount,purchase_amount;
    char status;

    printf("\nPlease Enter your Total Purchase Amount: ");
    scanf("%f",&purchase_amount);

    if(purchase_amount<0)
        printf("\nInvalid Amount!");
    else
    {
        printf("\nAre You a VIP member(Y/N): ");
        scanf(" %c",&status);

        if(purchase_amount<1000)
        {
            if(status =='Y'||status =='y')
            {
              discount = (purchase_amount*5)/100;
              printf("\nYou got a discount of Rs.%.2f",discount);
              purchase_amount= purchase_amount-discount;
              printf("\nYou have to pay Rs.%.2f",purchase_amount);
            }
            else
            {
                printf("\nNo discount upto this amount");
                printf("\nYou have to pay Rs.%.2f",purchase_amount);
            }
        }
        else if(purchase_amount>=1000 && purchase_amount<=2000)
        {
           if(status =='Y'||status =='y')
            {
              discount = (purchase_amount*15)/100;
              printf("\nYou got a discount of Rs.%.2f",discount);
              purchase_amount= purchase_amount-discount;
              printf("\nYou have to pay Rs.%.2f",purchase_amount);
            }
            else
            {
                discount = (purchase_amount*10)/100;
              printf("\nYou got a discount of Rs.%.2f",discount);
              purchase_amount= purchase_amount-discount;
              printf("\nYou have to pay Rs.%.2f",purchase_amount);
            }
        }
        else
        {
            discount = (purchase_amount*20)/100;
              printf("\nYou got a discount of Rs.%.2f",discount);
              purchase_amount= purchase_amount-discount;
              printf("\nYou have to pay Rs.%.2f",purchase_amount);
        }
    }
    return 0;

}
