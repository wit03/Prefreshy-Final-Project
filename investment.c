#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int monthPass = 0;
int monthDisplay = 0;
int yearDisplay = 0;

float currentMoney = 1000.00;
float change = 0.00;
float bankInterestAmount = 0.00;
float fundInterestAmount = 0.00;
float BankInterestRate = 6.00;

float fundInterestRateArr[20];

int currentSelection = 0;

int anouncement()
{
    printf("\nTime past: %d years %d months ***For debug monthPass: %d***\n", monthPass/12, monthPass%12, monthPass);
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
        fundInterestAmount = ((fundInterestRateArr[(int)(monthPass/3)]) * currentMoney)/100.00;
        currentMoney += (3.00 * fundInterestAmount);
         printf("\n***For debug: fundInterestAmount: %f***", fundInterestAmount);
        printf("\n***For debug: fundInterestRateArr %f***", fundInterestRateArr[(int)(monthPass/3)]);
        
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

void generateRandom() {
    for(int i = 0; i < 20; i++) {
        fundInterestRateArr[i] = rand() % (8 + 1 - 3) + 3;   
    }
}


void changeCal() {
    float sizeArr[11] = { 1000.00, 500.00, 100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25 };
    
    for(int i = 0; i < 11; i++) {
        printf("\n%.2f Majikite  x%d ", sizeArr[i], (int)floor(change/sizeArr[i]));
        change = fmod(change, sizeArr[i]);
    }
}

int main()
{
    generateRandom();
    printf("Start Money: %.2f Majikite\n", currentMoney);
    printf("\n");

    while (monthPass < 60)
    {
        anouncement();
        if(currentSelection == 2) {
            interestAnouncement(fundInterestRateArr[(int)(monthPass-3.00)/3] , monthPass-3.00);
            interestAnouncement(fundInterestRateArr[(int)monthPass/3], monthPass);
        } else if (currentSelection == 1) {
            interestAnouncement(fundInterestRateArr[(int)monthPass/3], monthPass);
        }
        questions();
    }

    printf("Final Money: %.2f Majikite", currentMoney);
    change = currentMoney;

    changeCal();
    return 0;
}
