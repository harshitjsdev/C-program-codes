/* Automated traffic Fine Generator:
Input: driver's actual speed.
Safe zone - if driving within a speed limit print within a speed limit driving.
Minor offense- if limit exceeds(41-55) Rs.50 fine per extra speed
Major offense- if limit exceeds(56-80) flat fine Rs.1000 and warning.
Reckless driving- if they exceeds 80km/h, flat Rs.2000 fine & alert of licence cancel*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int speed,fine=0, speed_limit= 40;


    printf("\nEnter driver's speed: ");
    scanf("%d",&speed);

    if(speed<0)
        printf("\nInvalid Speed!");
    else
        {
            printf("\nSpeed limit for the Automobile is: %dKm/h",speed_limit);
            printf("\npress any key to continue");
            getch();
            system("cls");
            if(speed<=speed_limit)
               printf("\nDriving within a speed limit");
            else
            {
                if(speed<=55)
                {
                    fine = (speed-speed_limit)*50;
                }
                else if(speed<= 80&& speed>=56)
                {
                    fine = 1000;
                    printf("\nCancel Licence next time");

                }
                else
                {
                    fine = 2000;
                    printf("\nLicence cancelled!");
                }
                printf("\nSpeed limit exceeds!");
                printf("\nFine to be charged: Rs.%d",fine);
            }
        }

    return 0;
}
