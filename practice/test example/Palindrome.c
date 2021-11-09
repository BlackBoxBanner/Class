#include <stdio.h>

//The checkPalindrome function must receive only one parameter and return character 'y' if the parameter is a palindrome and return character 'n' if the parameter is not a palindrome.
char checkPalindrome(char *str)
{
    int i, j, len;
    char ch;
    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    i = 0;
    j = len - 1;
    while (i < j)
    {
        while (str[i] == ' ')
        {
            i++;
        }
        while (str[j] == ' ')
        {
            j--;
        }
        if (str[i] != str[j])
        {
            return printf("Number %s is not palindrome.", str);
        }
        i++;
        j--;
    }
    return printf("Number %s is palindrome.", str);
}

//The output will be printed in the main function by checking the return result of the checkPalindrome function.
//In the main function, you must check the value of the input. If the input is in the range [0,1000000), the checkPalindrome function is called. Otherwise, print "ERROR".

int main()
{
    char str[100];
    scanf("%s", str);
    if (str[0] >= '0' && str[0] <= '9')
    {
        printf("%c", checkPalindrome(str));
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}