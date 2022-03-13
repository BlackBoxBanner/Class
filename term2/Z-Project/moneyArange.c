#include <stdio.h>

int main()
{
  int money, totalMoney, amount = 0;
  scanf("%d", &money);
  totalMoney = money;

  amount = money / 1000;
  money = money % 1000;
  if (amount > 0)
  {
    printf("%10s : %d \n", "1,000 bill", amount);
  }
  amount = money / 500;
  money = money % 500;
  if (amount > 0)
  {
    printf("%10s : %d \n", "500 bill", amount);
  }
  amount = money / 100;
  money = money % 100;
  if (amount > 0)
  {
    printf("%10s : %d \n", "100 bill", amount);
  }
  amount = money / 50;
  money = money % 50;
  if (amount > 0)
  {
    printf("%10s : %d \n", "50 bill", amount);
  }
  amount = money / 20;
  money = money % 20;
  if (amount > 0)
  {
    printf("%10s : %d \n", "20 bill", amount);
  }
  amount = money / 10;
  money = money % 10;
  if (amount > 0)
  {
    printf("%10s : %d \n", "10 coin", amount);
  }
  amount = money / 5;
  money = money % 5;
  if (amount > 0)
  {
    printf("%10s : %d \n", "5 coin", amount);
  }
  amount = money / 1;
  money = money % 1;
  if (amount > 0)
  {
    printf("%10s : %d \n", "1 coin", amount);
  }
  printf("Total exchange money : %d \n", totalMoney);
  return 0;
}
