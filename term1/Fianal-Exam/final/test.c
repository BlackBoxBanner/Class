#include <stdio.h>
#include <string.h>
void swap(char *a, char *b);

int main(int argc, char const *argv[])
{
    char s[] = "CPEKMUTT";
    char t[25];
    char *ps, *pt;
    ps = s;
    pt = t;
    while (*ps)
    *pt++ = *ps++;
    *pt='\n';
    printf("%s\n", t);
    return 0;
}
