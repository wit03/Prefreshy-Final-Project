#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int monthPass = 0;
int monthDisplay = 0;
int yearDisplay = 0;

float currentMoney = 1000.00;
float bankInterestAmount = 0.00;
float fundInterestAmount = 0.00;
float BankInterestRate = 6.00;
float fundInterestRate = 0.00;


int currentSelection = 0;

int anouncement()
{
    printf("\nTime past: %d years %d months (For debug monthPass: %d)\n", monthPass/12, monthPass%12, monthPass);
    printf("Current Money: %.2f Majikite\n", currentMoney);
    printf("\n");
    return 0;
}

int interestAnouncement(float fundInterest, int monthParse)
{
    printf("In %d year %d month, the interest of the fund is %.2f %c \n", monthParse/12, monthParse%12, fundInterest, '%');
    printf("\n");
    return 0;
}

int questions()
{
    printf("What do you want to choose next?\n");
    printf("1. Majikleen Fund (3-8%c) 3 months\n", '%');
    printf("2. Bank (6%c) 6 months\n", '%');
    printf("\n");
    printf("Your Selection: ");
    scanf("%d", &currentSelection);

    if (currentSelection == 1) //select fund
    {
        monthPass += 3;
        fundInterestAmount = (fundInterestRate/100) * currentMoney;
        currentMoney += (3.00 * fundInterestAmount);
    }
    else if (currentSelection == 2) //select bank
    {
        monthPass += 6;
        bankInterestAmount = ((BankInterestRate/100) * currentMoney);
        currentMoney += (6.00 * bankInterestAmount);
    }
    else
    {
        printf("\nFalse Selection, please re-select\n");
    }
return 0;
}

int main()
{
    printf("Start Money: %.2f Majikite\n", currentMoney);
    printf("\n");

    while (monthPass < 60)
    {
        srand(time(NULL));
        fundInterestRate = rand() % (8 + 1 - 3) + 3;
        anouncement();
        if(currentSelection == 2) {
            float fundInterestRate1 = rand() % (8 + 1 - 3) + 3;
            float fundInterestRate2 = rand() % (8 + 1 - 3) + 3;
            interestAnouncement(fundInterestRate1, monthPass-3.00);
            interestAnouncement(fundInterestRate2, monthPass);
        } else if (currentSelection == 1) {
            interestAnouncement(fundInterestRate, monthPass);
        }
        questions();
    }

    printf("Final Money: %.2f Majikite", currentMoney);

    float change = currentMoney;
    if(change >= 1000.00){
        printf("\n1000 Majikite  x%.2f ", change/1000.00);
        change = fmod(change, 1000.00);
    }
      
    if(change >= 500.00){
        printf("\n500 Majikite  x%.2f ", change/500.00);
        change = fmod(change, 500.00);
    }
      
    if(change >= 100.00){
        printf("\n100 Majikite  x%.2f ", change/100.00);
        change = fmod(change, 100.00);
    }

    if(change >= 50.00){
        printf("\n50 Majikite  x%.2f ", change/50.00);
        change = fmod(change, 50.00);
    }

    if(change >= 20.00){
        printf("\n20 Majikite  x%.2f ", change/20.00);
        change = fmod(change, 20.00);
    }
      
   if(change >= 10.00){
        printf("\n10 Majikite  x%.2f ", change/10.00);
        change = fmod(change, 10.00);
    }
      
    // if(change >= 5){
    //     printf("\n   5 Baht = %d", change/5);
    //     change = change % 5;
    // }
      
    // if(change >= 2){
    //     printf("\n   2 Baht = %d", change/2);
    //     change = change % 2;
    // }
      
    // if(change >= 1){
    //     printf("\n   1 Baht = %d", change);
    // }


    return 0;
}
