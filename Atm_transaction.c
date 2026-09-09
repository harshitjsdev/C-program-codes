#include<stdio.h>
int main()
{
    /* ATM CASH WITHDRAWAL-
    pin validity
    depense cash if available
    change PIN
    deposit Cash
    */
    int saved_pin,entered_pin;
    double balance,amount;
    char key;

    saved_pin = 2342;
    balance = 50000;

    printf("\t\tWELCOME TO ATM \n");
    printf("\nPlease enter 4 digit pin: ");
    scanf("\n%d",&entered_pin);

    if(saved_pin==entered_pin)
    {
        printf("\nCorrect pin");
        printf("\n-------------------------");
        printf("\nPress 1 to Withdraw cash");
        printf("\nPress 2 to Change PIN");
        printf("\nPress 3 to Deposit cash");
        printf("\nPress 4 to Check balance");
        printf("\n-------------------------");
        scanf(" %c",&key);
        if(key=='1')
        {
            printf("\nEnter Amount to withdraw: ");
            scanf("%lf",&amount);
            if(amount<=balance)
            {
                printf("\n%.3lf debited from your Account",amount);
                balance = balance-amount;
                printf("\nAvailable balance = %.3lf ",balance);
            }
            else
                printf("\nInsufficient Amount!");
        }
        else if(key=='2')
        {
            printf("\nEnter New PIN: ");
            scanf("%d",&entered_pin);
            printf("\nNew pin saved successfully");
            printf("\nOld pin is %d",saved_pin);
            saved_pin= entered_pin;
            printf("\nNew pin is %d",saved_pin);
        }
        else if(key=='3')
            {
                printf("\nEnter Amount to deposit: ");
                scanf("%lf",&amount);
                printf("Amount deposited Successfully");
                printf("\nOld balance = Rs.%.3lf",balance);
                balance = balance + amount;
                printf("\nNew balance = Rs.%.3lf",balance);
            }
         else if(key =='4')
                printf("\nYour Available balance is Rs.%.3lf",balance);
    }
    else
        printf("\nWrong PIN please Try Again!");

}
