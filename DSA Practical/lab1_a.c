#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    char grade;
};
int main()
{
    int n,i;
    
    printf("Enter the number of student : ");
    scanf("%d",&n);
    struct Student students[n];
    char sname[n];

    for (i = 0; i < n; i++) 
    {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);  
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }

    printf("\nEnter name of student to search marks: ");
    scanf(" %[^\n]s",sname);

    bool found = false;
    for (i = 0; i < n; i++) 
    {
        if (strcmp(students[i].name, sname) == 0) 
        {
            printf("Marks of %s: %.2f\n", students[i].name, students[i].marks);
            found = true;
            break;
        }
    }

    if (!found) 
        printf("Student with name '%s' not found.\n", sname);

    return 0;

}
