
/********** STUDENT MANAGEMENT SYSTEM ***********/
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct student /** STUDENT STRUCTURE **/
{
    int rollno,age;
    char name[20],course[20],grade;
    float marks;
};


int uniquerollno() /** Unique roll number verification function **/
{
    struct student s2;
    int rn,flag1;

        while(1)
        {
        printf("\nEnter Roll no:");
        scanf("%d",&rn);
        while (getchar() != '\n');

        if(rn<=0)
        {
            printf("\nEnter valid roll number!");
            continue;
        }
        flag1 =0;
        FILE *fp = fopen("studentrecord.txt", "rb");
        if (fp!=NULL)                      // no file = no duplicates
        {
           while(fread(&s2,sizeof(struct student),1,fp)==1)
              {
                  if(rn==s2.rollno)
                        {
                        flag1 = 1;
                        break;
                        }
              }
              fclose(fp);
        }
        if(flag1)
            printf("\nRoll number already exists! ");
        else
            return rn;
        }
}


int verifyage() /** Age verification function**/
{
    int Age;
    while(1)
    {
        printf("\nEnter Age:");
        scanf("%d",&Age);
        while (getchar() != '\n');
        if(Age>0 && Age<100)
            return Age;
        else
            printf("\nEnter valid age!");
    }
}


float verifymarks() /** marks verification function **/
{
    float m;
    while(1)
    {
        printf("\nMarks obtained(Out of 100):");
        scanf("%f",&m);
        while (getchar() != '\n');
        if(m>=0 && m<=100)
            return m;
        else
            printf("\nEnter Valid marks(0-100)");
    }
}


char calculategrade(struct student st) /** Grade calculation function **/
{
    if(st.marks>=90)
        return 'O';
    else if(st.marks>=80)
        return 'E';
    else if(st.marks>=70)
        return 'A';
    else if(st.marks>=60)
        return 'B';
    else if(st.marks>=50)
        return 'C';
    else if(st.marks>=33)
        return 'D';
    else
        return 'F';
}


void highestmarks() /** Rank holder(s) identification function **/
{
    struct student s;
    float max = -1;

    FILE *fp;
    fp = fopen("studentrecord.txt","rb");
    if(fp == NULL)
    {
    printf("No records found!");
    return;
    }


    while(fread(&s,sizeof(struct student),1,fp)==1)
    {
        if(s.marks>max)
            max = s.marks;
    }
    rewind(fp);
    printf("\n***************************");
    printf("\nTopper(s) with %.2f marks:\n", max);
    while (fread(&s, sizeof(struct student), 1, fp) == 1)
        {
            if(s.marks == max)
            {
                printf("\nROLL NO: %d  NAME: %s", s.rollno, s.name);
                printf("\n--------------------------");
            }
        }
        printf("\n***************************");
    fclose(fp);
}


void addstudent() /** Add student record function **/
{
    struct student s;

    s.rollno = uniquerollno();

    printf("\nName:");
    fgets(s.name,sizeof(s.name),stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove trailing newline

    s.age = verifyage();

    printf("\nCourse:");
    fgets(s.course,sizeof(s.course),stdin);
    s.course[strcspn(s.course, "\n")] = '\0'; // Remove trailing newline

    s.marks = verifymarks();
    s.grade = calculategrade(s);

    FILE *fp; // storing data in file
    fp = fopen("studentrecord.txt","ab");
    if(fp == NULL)
    {
    printf("Unable to open file!");
    return;
    }


    fwrite(&s,sizeof(struct student),1,fp);
    fclose(fp);
    printf("\nStudent added successfully!");
    printf("\npress enter to return<-");
    getch();

}


void updatestudent() /** Update student record function **/
{
    struct student s4;
    int us,flag3=0;

    printf("\nEnter Roll no: ");
    scanf("%d",&us);
    while (getchar() != '\n');

    FILE *fp = fopen("studentrecord.txt", "rb");
    if (fp == NULL)
    {
        printf("\nNo records found or file error!");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL)
    {
        printf("\nTemp file error!");
        fclose(fp);
        return;
    }

    while (fread(&s4, sizeof(struct student), 1, fp) == 1)
    {
        if(s4.rollno==us)
        {
           flag3 =1;
           printf("\n-------------------------");
           printf("\nRoll No: %d", s4.rollno);
           printf("\nName: %s", s4.name);
           printf("\nAge: %d", s4.age);
           printf("\nCourse: %s", s4.course);
           printf("\nMarks: %.2f", s4.marks);
           printf("\nGrade: %c", s4.grade);
           printf("\n-------------------------\n");

        printf("\nEnter new details:");

        printf("\nName:");
        fgets(s4.name,sizeof(s4.name),stdin);
        s4.name[strcspn(s4.name, "\n")] = '\0'; // Remove trailing newline

        s4.age = verifyage();

        printf("\nCourse:");
        fgets(s4.course,sizeof(s4.course),stdin);
        s4.course[strcspn(s4.course, "\n")] = '\0'; // Remove trailing newline

        s4.marks = verifymarks();
        s4.grade = calculategrade(s4);

        }
        fwrite(&s4,sizeof(struct student),1,temp);
    }
        fclose(fp);
        fclose(temp);

        if(flag3)
        {
        remove("studentrecord.txt");
        rename("temp.txt", "studentrecord.txt");
        printf("\nStudent record updated!");
        }
        else
        {
        remove("temp.txt");
        printf("\nNo student record found!");
        }

    printf("\npress enter to return<-");
    getch();
}


void displaystudent() /** Display student record function **/
{
    struct student s;
    system("cls");
    FILE *fp;
    fp = fopen("studentrecord.txt","rb");
    if (fp == NULL)
        {
        printf("\nNo records found or file error!");
        return;
        }

    while(fread(&s, sizeof(struct student), 1, fp) == 1)
        {
        printf("\n-------------------------");
        printf("\nRoll No: %d", s.rollno);
        printf("\nName: %s", s.name);
        printf("\nAge: %d", s.age);
        printf("\nCourse: %s", s.course);
        printf("\nMarks: %.2f", s.marks);
        printf("\nGrade: %c", s.grade);
        }
        printf("\n-------------------------\n");
    fclose(fp);
    printf("\npress enter to return<-");
    getch();
}


void searchstudent() /** Search student record function **/
{
    struct student s;
    int ss,flag=0;

    printf("\nEnter Roll no: ");
    scanf("%d",&ss);
    while (getchar() != '\n'); // clear buffer

    system("cls");
    FILE *fp;
    fp = fopen("studentrecord.txt","rb");

    if(fp == NULL)
        {
        printf("\nNo records found or file error!");
        return;
        }

    while(fread(&s, sizeof(struct student), 1, fp) == 1)
    {
        if(ss==s.rollno)
        {
           printf("\nRoll No: %d", s.rollno);
           printf("\nName: %s", s.name);
           printf("\nAge: %d", s.age);
           printf("\nCourse: %s", s.course);
           printf("\nMarks: %.2f", s.marks);
           printf("\nGrade: %c", s.grade);
           flag = 1;
           break;
        }
    }
    fclose(fp);
    if(!flag)
        printf("\nNo student record found!");
    printf("\npress enter to return<-");
    getch();
}


void deletestudent() /** Delete student record function **/
{
    struct student s3;
    int ds,flag2=0;

    printf("\nEnter Roll no: ");
    scanf("%d",&ds);
    while (getchar() != '\n');

    FILE *fp = fopen("studentrecord.txt", "rb");
    if (fp == NULL)
    {
        printf("\nNo records found or file error!");
        return;
    }

    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL)
    {
        printf("\nTemp file error!");
        fclose(fp);
        return;
    }

    while (fread(&s3, sizeof(struct student), 1, fp) == 1)
    {
        if (s3.rollno == ds)
            flag2 = 1;
        else
            fwrite(&s3, sizeof(struct student), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    if(!flag2)
    {
        remove("temp.txt");   // no student found
        printf("\nNo student record found!");
    }
    else
    {
        remove("studentrecord.txt");
        rename("temp.txt", "studentrecord.txt");
        printf("\nRecord deleted!");
    }
    printf("\npress enter to return<-");
    getch();

}


void statistics() /** Class statistics function **/
{
  struct student s5;
  int ps=0,fs=0,count=0;
  float total=0,avg;

  system("cls");
  FILE *fp = fopen("studentrecord.txt", "rb");
    if (fp == NULL)
    {
        printf("\nNo records found or file error!");
        return;
    }

  while(fread(&s5,sizeof(struct student),1,fp)==1)
  {
      total += s5.marks;
        count++;

     if(s5.marks>=33)
        ps++;
     else
        fs++;
  }
  fclose(fp);

  if(count==0)
    printf("\nNo records");
  else
  {
    avg = total/count;
    printf("\nTotal students: %d",count);
  printf("\nAverage Marks: %.2f",avg);
  printf("\nPassed students: %d",ps);
  printf("\nFailed students: %d",fs);
  highestmarks();
  }
  printf("\npress enter to return<-");
    getch();
}


int main()  /** Main function **/
{
    char key;
    do
    {
        system("cls");
        printf("\n******** STUDENT MANAGEMENT SYSTEM ********");
        printf("\n1.Add Student");
        printf("\n2.Update Student");
        printf("\n3.Display all Students");
        printf("\n4.Search Student");
        printf("\n5.Delete Student");
        printf("\n6.Class Statistics");
        printf("\n7.Exit");
        printf("\n*******************************************");
        printf("\nEnter Choice:");
        scanf(" %c",&key);

        switch(key)
        {
            case '1': addstudent();
                        break;
            case '2': updatestudent();
                        break;
            case '3': displaystudent();
                        break;
            case '4': searchstudent();
                        break;
            case '5': deletestudent();
                        break;
            case '6': statistics();
                        break;
           case '7': printf("\nExiting program.....");
                        break;
            default:
                    printf("\nInvalid choice!\n");
                    getch();
                        break;
        }

    }while(key!='7');
    return 0;
}


/** Read Me **/
/*
1. made a seperate structure of student for reusability and to avoid code repetition.

2. made a seperate function to identify and store only unique roll number to avoid duplicacy.
        A. while (getchar() != '\n'); function is taken from internet to clear buffer and to avoid skipping of input.
        B. used in addstudent function.

3. made a seperate age verification function to register only valid age of student.
        A. while(1) looping the while statement till get return or break , Logic taken from internet.
        B. A flaw in function - if user writes twenty instead of 20 is not fixed yet.
        C. Used in addstudent and updatestudent functions.

4. made a seperate marks verification function to register only valid marks of student.
        A. A flaw in function - if user hit ninty instead of 90 is not fixed yet!.
        B. Used in addstudent and updatestudent functions.

5. A self grade calculation function that calculates grades automaticaly with help of marks by accessing student structure as parameter.
        A. Used in addstudent key function.

6. A rank holder identification function to find student(s) with highest marks.
        A. used in class statistics function.
        B. (fp == NULL) Logic taken from internet to check if file contains data or not.
        C. frewind() taken from internet to set the fp pointer to starting without reopening the file.

7. A function which add students in record if all inputs are valid
        A. s.name[strcspn(s.name, "\n")] = '\0'; Logic taken from internet to remove trailing newline.

8.
*/

