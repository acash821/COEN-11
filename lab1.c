#include <stdio.h>
#include <stdlib.h>
int main()
{
int count = 0;
int right = 0;
srand((int) time (NULL));
while(count < 10)
{
int divisor, quotient, answer;
divisor = rand() % 12 + 1;
quotient = rand() % 13;
printf("Dividend: ");
printf("%d",divisor * quotient);
printf("\n");
printf("Quotient: ");
printf("%d", quotient);
printf("\n");
printf("Enter the result ");
scanf("%d", &answer);
printf("\n");
if(answer == divisor)
{
printf("True");
right++;
printf("\n");
}
else
{
printf("False, the answer was ");
printf("%d", divisor);
printf("\n");
}
count++;
}
printf("your score was ");
printf("%d",right);
printf(" out of 10");
return 0;
}