#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 81

#define fileName "info.dat"

/*
struct studentInfo
{
    int studentID;
    char studentName[100];
    int num1;
    int num2;
};

struct MyInfo
{
    int studentID;
    char studentName[100];
    int num1;
    int num2;
};

void displayStudent(struct studentInfo *student, int i)
{
    printf("\nStudent ID: %d\n", student[i].studentID);
    printf("Student Name: %s\n", student[i].studentName);
    printf("Number 1: %d\n", student[i].num1);
    printf("Number 2: %d\n", student[i].num2);
}

int getStudent(struct studentInfo *studentList)
{
    int i, numlines = 0;
    char buffer[256], c;
    // open the file
    FILE *pIn = NULL;
    pIn = fopen(fileName, "rb");

    if (pIn == NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    for (c = getc(pIn); c != EOF; c = getc(pIn))
        if (c == '\n') // Increment count if this character is newline
        {
            numlines++;
        }


    printf("%d", numlines);

    displayStudent(studentList, i);

    // close the file
    fclose(pIn);
}

int main()
{
    struct studentInfo studentList[100];
    getStudent(studentList);
    return 0;
}
 */