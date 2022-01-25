#include<stdio.h>

int main(int argc, char const *argv[])
{
    double Miles, GelG, AmG, Park, Tolls;
    printf("Total miles driven per day : \n"); //ask and get the value
    scanf("%lf", &Miles);
    printf("Cost per gallon of gasoline : \n");
    scanf(" %lf", &GelG);
    printf("Average miles per gallon : \n");
    scanf(" %lf", &AmG);
    printf("Parking fees per day : \n");
    scanf(" %lf", &Park);
    printf("Tolls per day : \n");
    scanf(" %lf", &Tolls);
    printf("Cost per day : %.2lf$", ((Miles/AmG)*GelG)+Park+Tolls); //print the value that are in the box
    return 0;
}
