#include <stdio.h>
#include <ctype.h>

void ConvertToUppercause(char *sPtr)
{
    while (*sPtr != '\0')
    {
        *sPtr = toupper( *sPtr);
        ++sPtr;
    }
    
}

int main()
{
    char string[] = "CharEcters aNd $32.98";

    printf("The string before converstion is : %s\n", string);
    ConvertToUppercause(string);
    printf("The string after converstion is : %s\n", string);
    return 0;
}
