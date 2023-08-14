#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30

struct Student
{
    char roll_no[15];
    char name[50];
    char Class[20];
    char course[50];
    char mobile_no[15];
    char admission_year[10];
};

struct Student students[MAX_STUDENTS];
int total = 0;

void enter()
{
    int ch = 0;
    printf("How many students do you want to enter?\n");
    scanf("%d", &ch);

    if (total + ch > MAX_STUDENTS)
    {
        printf("Maximum number of students reached!\n");
        return;
    }

    for (int i = total; i < total + ch; i++)
    {
        printf("\nEnter the Data of student %d\n\n", i + 1);
        printf("Enter Roll NO: ");
        scanf("%s", students[i].roll_no);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter Class: ");
        scanf("%s", students[i].Class);
        printf("Enter Course: ");
        scanf("%s", students[i].course);
        printf("Enter Mobile NO: ");
        scanf("%s", students[i].mobile_no);
        printf("Enter Admission Year: ");
        scanf("%s", students[i].admission_year);
    }

    total += ch;
}

void show()
{
    if (total == 0)
    {
        printf("No Data is Entered\n");
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            printf("\n                OUTPUT\n");
            printf("\nData of Student %d\n\n", i + 1);
            printf("Roll NO: %s\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Class: %s\n", students[i].Class);
            printf("Course: %s\n", students[i].course);
            printf("Mobile NO: %s\n", students[i].mobile_no);
            printf("Admission Year: %s\n", students[i].admission_year);
        }
    }
}

void search()
{
    if (total == 0)
    {
        printf("No data is entered\n");
    }
    else
    {
        char rollno[15];
        printf("Enter the roll no of student: ");
        scanf("%s", rollno);

        int found = 0;
        for (int i = 0; i < total; i++)
        {
            if (strcmp(rollno, students[i].roll_no) == 0)
            {
                printf("Data of Student %d\n\n", i + 1);
                printf("Roll NO: %s\n", students[i].roll_no);
                printf("Name: %s\n", students[i].name);
                printf("Class: %s\n", students[i].Class);
                printf("Course: %s\n", students[i].course);
                printf("Mobile NO: %s\n", students[i].mobile_no);
                printf("Admission Year: %s\n", students[i].admission_year);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Student with roll no %s not found\n", rollno);
        }
    }
}

void update()
{
    if (total == 0)
    {
        printf("No data is entered\n");
    }
    else
    {
        char rollno[15];
        printf("Enter the roll no of student you want to update: ");
        scanf("%s", rollno);

        int found = 0;
        for (int i = 0; i < total; i++)
        {
            if (strcmp(rollno, students[i].roll_no) == 0)
            {
                printf("\nPrevious data\n\n");
                printf("Data of Student %d\n", i + 1);
                printf("Roll NO: %s\n", students[i].roll_no);
                printf("Name: %s\n", students[i].name);
                printf("Class: %s\n", students[i].Class);
                printf("Course: %s\n", students[i].course);
                printf("Mobile NO: %s\n", students[i].mobile_no);
                printf("Admission Year: %s\n", students[i].admission_year);

                printf("\nEnter new data\n");
                printf("Enter Roll NO: ");
                scanf("%s", students[i].roll_no);
                printf("Enter Name: ");
                scanf("%s", students[i].name);
                printf("Enter Class: ");
                scanf("%s", students[i].Class);
                printf("Enter Course: ");
                scanf("%s", students[i].course);
                printf("Enter Mobile NO: ");
                scanf("%s", students[i].mobile_no);
                printf("Enter Admission Year: ");
                scanf("%s", students[i].admission_year);

                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Student with roll no %s not found\n", rollno);
        }
    }
}

void Delete()
{
    if (total == 0)
    {
        printf("No data is entered yet\n");
    }
    else
    {
        int a;
        printf("Are you sure you want to delete all data?\n");
        printf("Press 1 to delete all records: ");
        scanf("%d", &a);

        if (a == 1)
        {
            total = 0;
            printf("All records have been deleted\n");
        }
        else
        {
            printf("No records were deleted\n");
        }
    }
}

int main()
{
    int value;

    while (1)
    {
        printf("\n                    Student Record Management System ");
        printf("\n\n                         Press 1 to Enter data\n");
        printf("                         Press 2 to Show data\n");
        printf("                         Press 3 to Search data\n");
        printf("                         Press 4 to Update data\n");
        printf("                         Press 5 to Delete data\n");
        printf("                         Press 6 to Quit\n");
        printf("\nEnter the value\n");
        scanf("%d", &value);

        switch (value)
        {
        case 1:
            enter();
            break;
        case 2:
            show();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            Delete();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}
