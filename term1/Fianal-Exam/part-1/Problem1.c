#include <stdio.h>

/* typedef struct
{
    int id;
    char name[20];
    int age;
    float cgpa;
}student;

int main(int argc, char const *argv[])
{
    student s1[1000];
    int studentID = 1;
    // get id from user
    do
    {
        printf("Enter id: ");
        scanf("%d", &studentID);
        // store studentID into s1->id
        s1[studentID].id = studentID;
        // get user name
        printf("Enter name: ");
        scanf("%s", &s1[studentID].name);
        // get user age
        printf("Enter age: ");
        scanf("%d", &s1[studentID].age);
        // get user cgpa
        printf("Enter cgpa: ");
        scanf("%f", &s1[studentID].cgpa);
        // print the student details
        // new line
        printf("\n");
        printf("Student id: %d\n", s1[studentID].id);
        printf("Student name: %s\n", s1[studentID].name);
        printf("Student age: %d\n", s1[studentID].age);
        printf("Student cgpa: %.2f\n\n", s1[studentID].cgpa);

        int q;
        printf("Do you want to review data? (1/0): ");
        scanf("%d", &q);
        if (q == 0)
        {
        }
        else
        {
            int numofstudentsid;
            printf("Enter student id to review: ");
            scanf("%d", &numofstudentsid);
            printf("Student id: %d\n", s1[numofstudentsid].id);
            printf("Student name: %s\n", s1[numofstudentsid].name);
            printf("Student age: %d\n", s1[numofstudentsid].age);
            printf("Student cgpa: %.2f\n\n", s1[numofstudentsid].cgpa);
        }

    } while (studentID != 0);
    return 0;
} */

int main()
{
    int *pc, c;

    c = 22;
    printf("Address of c: %p\n", &c);
    printf("Value of c: %d\n\n", c); // 22

    pc = &c;
    printf("Address of pointer pc: %p\n", pc);
    printf("Content of pointer pc: %d\n\n", *pc); // 22

    c = 11;
    printf("Address of pointer pc: %p\n", pc);
    printf("Content of pointer pc: %d\n\n", *pc); // 11

    *pc = 2;
    printf("Address of c: %p\n", &c);
    printf("Value of c: %d\n\n", c); // 2
    return 0;
}