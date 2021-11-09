/*
 *    writestudents2.c
 *
 *    Writes a binary file of STUDENT_T records
 *    prefixed by a count so that the reading program
 *    can dynamically allocate an array to hold the data.
 *
 *    Created by Sally Goldin, 23 August 2004.
 *    Updated 11 November 2013
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

/* Write a set of STUDENT_T records to the specified file, prefaced
 * by the count of the students. Return 0 for success, -1 for error
 */
int writeStudents(char* filename, STUDENT_T * students, int count);

int main()
{
  char* filename1 = "students1.dat";
  char* filename2 = "students2.dat";

  /* Initialize the arrays with some data */
  STUDENT_T students1[] = {{"Lek",19,'F',{10,9,6,8,9},3.4},
			    {"Suwannee",18,'F',{8,9,7,8,9},3.6},
			    {"Wandee",19,'F',{9,10,6,8,9},2.9},
			    {"Chaiwat",20,'M',{6,8,7,9,9},3.0},
			    {"Pattamaporn",22,'F',{10,9,8,9,9},3.9},
			    {"Arun",17,'F',{10,10,6,0,9},3.1},
			    {"Somchai",19,'M',{8,9,7,8,9},3.3},
			    {"Apilak",20,'M',{10,9,10,8,9},3.7},
			    {"Thongchai",20,'M',{5,9,6,8,9},2.6},
			    {"Ruangroj",19,'M',{8,9,4,6,7},3.0},
			    {"Matinee",18,'F',{10,6,9,8,9},2.9},
			    {"Somboon",22,'F',{8,9,8,8,9},3.5},
			    {"Ratchanee",19,'F',{6,8,9,10,10},3.1},
			    {"Nongnuch",18,'F',{9,6,10,8,9},3.8}};

  STUDENT_T students2[] = {{"Julie",19,'F',{10,9,6,8,9},3.4},
			    {"Louise",18,'F',{8,9,7,8,9},3.6},
			    {"Mary",19,'F',{9,10,6,8,9},2.9},
			    {"Joe",20,'M',{6,8,7,9,9},3.0},
			    {"Cindy",22,'F',{10,9,8,9,9},3.9},
			    {"Susan",17,'F',{10,10,6,0,9},3.1},
			    {"Robert",19,'M',{8,9,7,8,9},3.3},
			    {"James",20,'M',{10,9,10,8,9},3.7},
			    {"Alexander",20,'M',{5,9,6,8,9},2.6},
			    {"Brad",19,'M',{8,9,4,6,7},3.0},
			    {"Marilyn",18,'F',{10,6,9,8,9},2.9},
			    {"Helena",22,'F',{8,9,8,8,9},3.5},
			    {"Donna",19,'F',{9,10,6,8,9},2.9},
			    {"Stephen",20,'M',{6,8,7,9,9},3.0},
			    {"Christine",22,'F',{10,9,8,9,9},3.9},
			    {"Jennifer",17,'F',{10,10,6,0,9},3.1},
			    {"George",19,'M',{8,9,7,8,9},3.3},
			    {"Henry",20,'M',{10,9,10,8,9},3.7},
			    {"Carl",20,'M',{5,9,6,8,9},2.6},
			    {"Charles",19,'M',{8,9,4,6,7},3.0},
			    {"Loretta",18,'F',{10,6,9,8,9},2.9},
			    {"Martha",22,'F',{8,9,8,8,9},3.5},
			    {"Opal",19,'F',{6,8,9,10,10},3.1},
			    {"Linda",21,'F',{8,9,6,7,9},2.7},
			    {"Praew",18,'F',{10,10,10,6,8},3.9},
			    {"Brendan",19,'M',{5,10,7,8,8},3.1},
			    {"Julie",20,'F',{10,10,5,0,6},2.7},
			    {"Howard",21,'M',{5,6,6,1,4},2.3},
			    {"Thomas",19,'M',{7,8,8,8,9},3.4},
			    {"Nancy",18,'F',{9,6,10,8,9},3.8}};


  /* Compute the count using sizeof. Should be 14 and 24*/
  int count1 = (sizeof(students1)/sizeof(STUDENT_T));
  int count2 = (sizeof(students2)/sizeof(STUDENT_T));

  printf("Size of STUDENT_T is %d\n", sizeof(STUDENT_T));

  if (writeStudents(filename1,students1,count1) != 0)
     exit(1);
  if (writeStudents(filename2,students2,count2) != 0)
     exit(2);
  return 0;
  }

 
/* Write a set of STUDENT_T records to the specified file. 
 * Return 0 for success, -1 for error
 */
int writeStudents(char* filename, STUDENT_T * students, int count)
  {
  FILE * pOutfile = NULL;
  int status = 0;
  printf("Writing %d students to file %s\n", count, filename);
  /* Open the file */
  pOutfile = fopen(filename,"wb");
  if (pOutfile == NULL)
     {
     fprintf(stderr,"Error opening output file %s - exiting\n", filename);
     status = -1;
     }  
  else
     { 
     /* Write the count */
     if (fwrite(&count,sizeof(int),1,pOutfile) != 1)
        {
        fprintf(stderr,"Unexpected error writing count!\n");
        status = -1;
        } 
     /* Then write the actual data */
     else if (fwrite(students,sizeof(STUDENT_T), count, pOutfile) != count)
        {
        fprintf(stderr,"Unexpected error writing student data!\n");
        status = -2;
        } 
     fclose(pOutfile);
     } 
  return status;
  }
