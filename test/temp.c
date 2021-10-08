#include<stdio.h>
void convertToRoman(int number)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char *symbol[] = {"I","IV","V","XI","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    do
    {
        int div = number/num[i];
        number = number%num[i];
        while(div>0)
        {
            printf("%s",symbol[i]);
            div--;
        }
        i--;
    }while(num > 0);
}
int main()
{
    int num;
    scanf("%d",&num);
    if(num < 0 || num >= 5000)
        printf("ERROR");
    else
        convertToRoman(num);
    return 0;
}