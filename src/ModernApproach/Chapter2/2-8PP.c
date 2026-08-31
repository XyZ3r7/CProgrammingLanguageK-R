//
// Created by xyz3r7 on 8/31/26.
//
#include <stdio.h>
int main()
{
    float amount = 0.0, interestRate = 0, monthlyPayment = 0;
    printf("Enter amount of loan: \n");
    scanf("%f", &amount);
    printf("Enter interest rate: \n");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: \n");
    scanf("%f", &monthlyPayment);

    int i;
    for (i = 1; amount > 0.0; i++)
    {
        amount *= (1 + (interestRate/12.0/100.0));
        amount -= monthlyPayment;
        printf("Balance remaining after %d payment: %.2f\n", i, amount);
    }

}