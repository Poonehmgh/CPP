int digs(int n)
{
  int i = 1;
  while (n / 10)
  {
    n = n/10;
    i++;
  }
  return (i);
}
#include<stdio.h>

#include<math.h>

int isn(int num, int on)
{
    float tmp;
    tmp = (float)num / (float)on;
    if (tmp - num/on == 0)
        return (num/on);
    // printf("%f", tmp);
    return (tmp);
}

int digPow(int n, int p) {
  int num = 0;
  int digis = digs(n);
  int on = n;
  while (n % 10)
  {
    num += pow((n % 10), (p + digis - 1));
    n /= 10;
    digis--;
  }
  if (isn(num,on)> 0)
    return(num/on);
  return (-1);
}
int main(){

    printf("\n%d", digPow(89, 1));
}