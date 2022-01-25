#include<stdio.h>
int main ()
{
    double weight,height,bmi;
        printf("Enter your weight(Kilograms): ");
            scanf("%lf",&weight); //get the value for weight
        printf("Enter your height(Meters): ");
            scanf("%lf",&height); //get the value for height
          bmi= weight / (height * height);
        printf("BMI VALUES : %.1lf \n",bmi); //print the value
        printf("Underweight : less than 18.5\n");
        printf("Normal:       between 18.5 and 24.9\n");
        printf("Overweight:   between 25 and 29.9\n");
        printf("Obese:        30 or greater\n");
    return 0;


}
