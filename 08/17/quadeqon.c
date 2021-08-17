#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, determinant, root1, root2, realPart, imgnum; 

    printf("Enter cofficients a, b and c : "); 
    scanf("%lf %lf %lf", a, b, c); //get number for a, b and c
    determinant = b*b-4*a*c;
    if (determinant > 0) //check if determinant is more then 0
    {
        root1 = (-b+sqrt(determinant))/(2*a); //calculate root1
        root2 = (-b-sqrt(determinant))/(2*a); //calculate root2
        printf("root1 = %.2lf and root2 = %.2lf", root1 , root2); //print the statement
    }
    else if (determinant == 0) //check if determinat is 0
    {
        root1 = root2 = (-b)/(2*a); //calculate root1
        printf("root1 = root2 = %.2lf" , root1); //print the statement
    }
    else //if non of the above condition
    {
        realPart = -b/(2*a); //find realPart
        imgnum = sqrt(-determinant)*(2*a); //find imgnum
        printf("root1 = %.2lf + %.2lf and root2 = %.2lf - %.2lf", realPart,imgnum ,realPart ,imgnum); //print the statement
    }    
    return 0;
}
