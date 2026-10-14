#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int a[5][6],i,j,row,col,empty=0,booked=0;
    int key;
// making all seats empty.
    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            a[i][j] = 0;
        }
    }


    //Display Home Screen
    printf("HELLO USER\n");
    printf("Press any key to continue...");
    getch();
    system("cls");

    //Menu Bar
    printf("press 1 To see seating chart\n");
    printf("press 2 To book a seat\n");
    printf("press 3 To cancel the seat\n");
    printf("press 4 To exit\n");
    scanf(" %d",&key);
    system("cls");

    // Loop running until key 4 pressed.
    while(key!=4)
    {
    switch(key)
        {
        case 1:
                //caclulating seats status
                empty = 0;
                booked = 0;
                for(i=0;i<5;i++)
                {
                    for(j=0;j<6;j++)
                    {
                        if(a[i][j]==0)
                            empty++;
                        else if(a[i][j]==1)
                            booked++;
                    }
                }
                //Showing seats chart
                for(i=0;i<5;i++)
                {
                    printf("Row %d | ",i+1);
                    for(j=0;j<6;j++)
                    {
                        printf("%d ",a[i][j]);
                    }
                    printf("\n\t------------\n");
                }
                // showing seats results ( vacant or not )
                printf("\nTotal seat Available: %d",empty);
                printf("\nTotal seat booked: %d",booked);
                break;
        case 2:
                printf("\nEnter Row (1-5): ");
                scanf("%d",&row);
                printf("\nEnter seat (1-6): ");
                scanf("%d",&col);
                if(row>0 && row<6 && col>0 && col<7)
                {
                    if(a[row-1][col-1]==0)
                    {
                        a[row-1][col-1] = 1;
                        printf("\nSeat booked succesfully");
                    }
                    else
                        printf("\nSeat is already booked!");
                }
                else
                    printf("\nEntered wrong Row and column");
                    break;

        case 3:
                printf("\nEnter Row no: ");
                scanf("%d",&row);
                printf("\nEnter seat no: ");
                scanf("%d",&col);
                if(row<6 && row>0 && col>0 && col<7)
                {
                    if(a[row-1][col-1]==1)
                    {
                        a[row-1][col-1] = 0;
                        printf("\nSeat cancelled succesfully");
                    }
                    else
                        printf("\nSeat is already empty!");
                }
                else
                    printf("\nWrong seat number");
                    break;
            default:
                printf("\nInvalid key!");
                break;
        }
    printf("\nPress any key for menu\n");
    getch();
    system("cls");

    //Menu Bar
    printf("press 1 To see seating chart\n");
    printf("press 2 To book a seat\n");
    printf("press 3 To cancel the seat\n");
    printf("press 4 To exit\n");
    scanf(" %d",&key);
    system("cls");
    }
printf("\nThank you for booking.");
}
