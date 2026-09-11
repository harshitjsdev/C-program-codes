/*
Electric Grid "Slab Rate" Billing Calculator-

 INPUT: The number of Electricity Units consumed by a household.

 The Logic Rules:

        First 100 Units: ₹3.50 per unit.
        Next 150 Units (101 to 250): ₹5.00 per unit for this chunk.
        Units above 250: ₹7.50 per unit for this chunk.

 NOTE-  A fixed meter charge of ₹150 is added
        to every single bill regardless of consumption.

OUTPUT: Total_bill-*/
#include<stdio.h>
int main()
{
    int unit,temp_unit, fixed_charge= 150;
    float amount= 0,total_amount;

    printf("\nEnter amount of electricity unit consumed: ");
    scanf("%d",&unit);
    if(unit<0)
        printf("\nInvalid Unit!");
    else
        {
            if(unit>250)
        {
            temp_unit =unit -250;
            amount = 1100 + (temp_unit*7.5);
        }
        else if(unit>100 && unit<=250)
        {
            temp_unit= unit-100;
            amount = 350 + (temp_unit*5);
        }
        else
        {
            amount = unit*3.5;
        }
        total_amount = fixed_charge + amount;
        printf("\n---------------------------");
        if(unit<=100)
            printf("\nRate is 3.5rs per unit.");
        else if(unit>100 && unit<=250)
        {
            printf("\nRate for First 100 unit is 3.5rs.\n Rate for rest unit is 5rs.");
        }
        else
            printf("\nRate for First 100 unit is 3.5rs.\nRate for next 150 unit is 5rs.\nRate for rest unit is 7.5rs. ");
        printf("\n---------------------------");
        printf("\nAmount on %d unit is Rs %.2f",unit,amount);
        printf("\nFixed charge on metre is %drs.",fixed_charge);
        printf("\nTotal amount to pay: Rs %.2f",total_amount);
        }
    return 0;
}
