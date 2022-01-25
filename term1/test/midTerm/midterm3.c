#include<stdio.h>

void convertToRoman(int num)
{
    int orig[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char *rome[] = {"I","IV","V","XI","X","XL","L","XC","C","CD","D","CM","M"};
    int i = 12;
    int div;
    

    while (num >= 0)
    {
        div = num/orig[i];
        num %= orig[i];
        while(div>0)
        {
            printf("%s",rome[i]);
            div--;
        }
        i--;
    }
    
}

int main()
{
    int num;
    scanf("%d", &num);
    if (num < 0 || num >= 5000)
    {
        return printf("ERROR");
    }
    convertToRoman(num);
    return 0;
}
