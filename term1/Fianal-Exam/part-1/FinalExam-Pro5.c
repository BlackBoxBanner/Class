#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*structure of student information*/
typedef struct{
    char Name[30];
    int Midterm;
    int Final;
    int Assignment;
    double TotalScore;
}student_info;

/*Get input */
int GetInput(student_info student[])
{
    int i = 0;

    do
    {
        scanf("%s",student[i].Name);

        if(strcmp(student[i].Name,"END") != 0)
        {
            scanf("%d %d %d", &student[i].Assignment, &student[i].Midterm, &student[i].Final);
            i++;
        }
    }while(strcmp(student[i].Name,"END") != 0);

    return i;
}

/*Compute Total Score per Student*/
void ComputeTotalScores(student_info student[], int NumberOfStudents)
{
    int i;
    for(i = 0; i < NumberOfStudents; i++)
    {
        student[i].TotalScore = (int) (0.3*student[i].Assignment+0.3*student[i].Midterm+0.4*student[i].Final);
    }
}

/*Print scores for all students*/
void PrintScores(student_info student[], int NumberOfStudents)
{
    int i;
    printf("Number Students: %d\n", NumberOfStudents);
    printf("------------------------------|-----|-----|-----|-----\n");
    for(i = 0; i < NumberOfStudents; i++)
    {
        printf("%-30s %5d %5d %5d %5.0lf\n",student[i].Name,student[i].Assignment,student[i].Midterm,student[i].Final,student[i].TotalScore);
    }
}

int main()
{
    student_info student[30];
    int i, NumberOfStudents;
    i = GetInput(student);
    ComputeTotalScores(student,i);
    PrintScores(student,i);
}