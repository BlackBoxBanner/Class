#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strlwr(char *str)
{
    unsigned char *p = (unsigned char *)str;
    while (*p)

    {
        *p = tolower((unsigned char)*p);
        p++;
    }
    return str;
}
int isFunction(char *token)
{
    char *test = strlwr(token);
    char *func[] = {"sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "pow", "log", "exp", "abs"};
    for (int i = 0; i < 11; i++)
    {
        if (strcmp(test, func[i]) == 0)
            return i;
    }
    return -1;
}
int main()
{
    char s[255];
    scanf("%s", s);
    char token[255];
    strcpy(token, s);
    if (isFunction(token) != -1)
        printf("%s -> %d", token, isFunction(token));
    else
        printf("Not found");
    return 0;
}