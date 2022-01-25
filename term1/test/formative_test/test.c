#include<stdio.h>
#define MAXNUMBER 999


void remo7(int primeNum[],int i){
    int k = 0,rought=1,x=1;
    for(int u = 0 ; u < i ; u++){
        if(primeNum[u]%7 != 0){
            x++;
        }
    }
    int remo7[x];
    for(int j = 0 ; j < i ; j++){
        if(primeNum[j]%7!=0||primeNum[j]==7){
            remo7[k] = primeNum[j];
            k++;
        }
    }
    printf("\n[7] -- %d\n",x);
    for(int o = 0 ; o <= x-1 ; o++){
        printf("%5d",remo7[o]);
        rought++;
        if(rought == 20){
            printf("\n");
            rought = 1;
        }
    }
    printf("\n\n");
    rought=1;
    for(int o = 0 ; o <= x-1 ; o++){
        printf("%5d",remo7[o]);
        rought++;
        if(rought == 20){
            printf("\n");
            rought = 1;
        }
    }
}

void remo5(int primeNum[],int i){
    int k = 0,rought=1,x=1;
    for(int u = 0 ; u < i ; u++){
        if(primeNum[u]%5 != 0){
            x++;
        }
    }
    int remo5[x];
    for(int j = 0 ; j < i ; j++){
        if(primeNum[j]%5!=0||primeNum[j]==5){
            remo5[k] = primeNum[j];
            k++;
        }
    }
    printf("\n[5] -- %d\n",x);
    for(int o = 0 ; o <= x-1 ; o++){
        printf("%5d",remo5[o]);
        rought++;
        if(rought == 20){
            printf("\n");
            rought = 1;
        }
    }
    printf("\n");
    remo7(remo5,x);
}

void remo3(int primeNum[],int i){
    int k = 0,rought=1,x=1;
    for(int u = 0 ; u < i ; u++){
        if(primeNum[u]%3 != 0){
            x++;
        }
    }
    int remo3[x];
    for(int j = 0 ; j < i ; j++){
        if(primeNum[j]%3!=0||primeNum[j]==3){
            remo3[k] = primeNum[j];
            k++;
        }
    }
    printf("\n[3] -- %d\n",x);
    for(int o = 0 ; o <= x-1 ; o++){
        printf("%5d",remo3[o]);
        rought++;
        if(rought == 20){
            printf("\n");
            rought = 1;
        }
    }
    printf("\n");
    remo5(remo3,x);
}

void remo2(int num[],int i){
    int k = 0,rought=1,ModTwo[i/2];
    for(int j = 0 ; j < i-2 ; j++){
        if(num[j]%2==1||num[j]==2){
            ModTwo[k] = num[j];
            k++;
        }
    }
    int SizeModTwo = sizeof(ModTwo)/sizeof(ModTwo[0]);
    printf("[2] -- %d\n",SizeModTwo);
    for(int o = 0 ; o < k ; o++){
        printf("%5d",ModTwo[o]);
        rought++;

        if(rought == 20){
            printf("\n");
            rought = 1;
        }
    }
    printf("\n");
    remo3(ModTwo,SizeModTwo);
}

int main()
{
    int allnum[MAXNUMBER],maxNum,loop=1;
    for(int i=0;i<MAXNUMBER;i++){
        allnum[i]=i+2;
    }
    printf("Please enter a number [more than 2]: ");
    scanf("%d",&maxNum);
    
    remo2(allnum,maxNum);
    return 0;
}