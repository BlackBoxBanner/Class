#include <stdio.h>
# include <stdlib.h>
#include "student.h"

#define filename "students.dat"

void displayStudent(STUDENT_T oneStudent)
{
    printf("%s %d %c %d %d %d %d %d %.2lf\n",oneStudent.name, oneStudent.age, oneStudent.gender,oneStudent.quizGrades[0],oneStudent.quizGrades[1],oneStudent.quizGrades[2],oneStudent.quizGrades[3],oneStudent.quizGrades[4],oneStudent.gpa);
}

int main()
{
    STUDENT_T students[MAXCOUNT];
    FILE* pIn = NULL;
    FILE* pOut = NULL;
    int chk,i;

    pIn = fopen(filename,"rb"); //pIn == file name
    if(pIn == NULL)
    {
        printf("Error: cannot open file %s.\n", filename);
        exit(1);
    }

    // chk = fread (students,sizeof(STUDENT_T), 1,pIn);
    // printf("%d\n",chk);

    // chk = fread(&students[i], sizeof(STUDENT_T),1,pIn);
    // printf("%d\n",chk);

    i = 0;
    while (fread(&students[i], sizeof(STUDENT_T),1,pIn) && i < MAXCOUNT)
    {
        displayStudent(students[i]);
        i++;
    }
    chk = i;

    // for (int i = 0; i < chk; i++)
    // {
    //     printf("%s %d %c %d %d %d %d %d %.2lf\n",students[i].name, students[i].age, students[i].gender,students[i].quizGrades[0],students[i].quizGrades[1],students[i].quizGrades[2],students[i].quizGrades[3],students[i].quizGrades[4],students[i].gpa);
    // }
    
    fclose (pIn);

    pOut = fopen("newstudents.dat", "wb");

    if(pOut == NULL)
    {
        printf("Error: cannot open file newstudents.dat.\n");
        exit(1);
    }
    if(fwrite(students,sizeof(STUDENT_T),i,pOut) != i)
    {
        printf("Error: cannot write data to a newstudents.dat.\n");
    }
    fclose(pOut);
    return 0;
}