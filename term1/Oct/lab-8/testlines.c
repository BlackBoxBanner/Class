#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE* inFile = NULL; // The variable which points to the address of the input file.
    FILE* outFile = NULL;
    FILE* outFile2 = NULL;
    FILE* outFile3 = NULL;
    char filename[256]; // store file name.
    char buffer[256]; // a char to receive keyboard input.
    
    // Enter the file name
    printf("Enter the file name : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", filename);
    
    // Open the file
    inFile = fopen(filename, "r"); // 'r' means open the file just for reading.
    outFile = fopen("number.out", "w"); // 'w' means create a new file to write.
    outFile2 = fopen("upper.out", "w");
    outFile3 = fopen("lower.out", "w");
    
    // Check error file.
    if(inFile == NULL)
    {
        printf("Error opening the file : %s\n", filename);
        exit(1);
    }
    if(outFile == NULL)
    {
        printf("Error opening the file : number.out\n");
        exit(1);
    }
    if(outFile2 == NULL)
    {
        printf("Error opening the file : upper.out\n");
        exit(1);
    }
    if(outFile3 == NULL)
    {
        printf("Error opening the file : lower.out\n");
        exit(1);
    }
    
    while(fgets(buffer, sizeof(buffer), inFile) != NULL)
    {
        if(isdigit(buffer[0]))
        {
            printf("%s", buffer);
            fprintf(outFile, "%s", buffer); // this writes the buffer in the outFile.
        }
        if(isupper(buffer[0]))
        {
            printf("%s", buffer);
            fprintf(outFile2, "%s", buffer);
        }
        if(islower(buffer[0]))
        {
            printf("%s", buffer);
            fprintf(outFile3, "%s", buffer);
        }
    }
    fclose(inFile);
    fclose(outFile);
    fclose(outFile2);
    fclose(outFile3);
    return 0;
}
