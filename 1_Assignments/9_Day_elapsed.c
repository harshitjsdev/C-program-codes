#include<stdio.h>
void main()
{
    int a[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i,month,date,sum=0,fixed_month;

        printf("\nEnter the Month: ");
        scanf("%d",&month);

    if(month>0 && month<=12)
    {
        fixed_month = month-1;
        printf("\nEnter the Date: ");
        scanf("%d",&date);

        if(date>0 && date<=a[fixed_month])
        {
                for(i=0;i<fixed_month;i++)
                {
                sum += a[i];
                }
                sum += date-1;
                printf("\nNo of days elapsed till %d/%d : %d",date,month,sum);
        }
        else
            printf("\nInvalid Date!");
    }
    else
        printf("\nInvalid Month!");
}
