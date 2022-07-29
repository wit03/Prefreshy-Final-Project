#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int monthPass = 0;

float currentMoney = 1000.00;
float change = 0.00;
float bankInterestAmount = 0.00;
float fundInterestAmount = 0.00;
float BankInterestRate = 6.00;

float fundInterestRateArr[20];
int decisionHistoryArr[20] = {0};

int currentSelection = 0;
int previousSelection = 0;

float bestSum = 0.00;

void anouncement()
{
    printf("\nTime past: %d years %d months ***For debug monthPass: %d***\n", monthPass / 12, monthPass % 12, monthPass);
    printf("Current Money: %.2f Majikite\n", currentMoney);
    printf("\n");
}

void interestAnouncement(float fundInterest, int monthParse)
{
    printf("In %d year %d month, the interest of the fund is %.2f %c \n", monthParse / 12, monthParse % 12, fundInterest, '%');
    printf("\n");
}

void questions()
{
    printf("What do you want to choose next?\n");
    printf("1. Majikleen Fund (3-8%c) 3 months\n", '%');
    printf("2. Bank (%.2f%c) 6 months\n", BankInterestRate, '%');
    printf("3. Undo");
    printf("\n");
    printf("Your Selection: ");
    scanf("%d", &currentSelection);

    if (currentSelection == 1) // select fund
    {   
        previousSelection = currentSelection;
        monthPass += 3;
        fundInterestAmount = ((fundInterestRateArr[(int)(monthPass / 3)]) * currentMoney) / 100.00;
        currentMoney += (3.00 * fundInterestAmount);
        decisionHistoryArr[monthPass / 3] = 1;
        printf("\n***For debug: fundInterestAmount: %f***", fundInterestAmount);
        printf("\n***For debug: fundInterestRateArr %f***", fundInterestRateArr[(int)(monthPass / 3)]);
    }
    else if (currentSelection == 2) // select bank
    {
        previousSelection = currentSelection;
        monthPass += 6;
        bankInterestAmount = ((BankInterestRate / 100) * currentMoney);
        currentMoney += (6.00 * bankInterestAmount);
        decisionHistoryArr[monthPass / 3] = 2;
    }
    else if (currentSelection == 3) //select undo
    {
        if(BankInterestRate > 2.00) {
            if(previousSelection == 1) { //chose fund
               monthPass -= 3;
                currentMoney -= (3* fundInterestAmount);
                decisionHistoryArr[monthPass / 3] = 0;
                 
                
            } else if (previousSelection == 2) { //chose bank
                monthPass -= 6;
                currentMoney -= (6* bankInterestAmount);
                decisionHistoryArr[monthPass / 3] = 0;
                
            }
            printf("\n\n***For debug: previous selection %d ***\n\n", previousSelection);
            questions();
            BankInterestRate--;
            
        } else {
            printf("\nYou can't undo anymore, continue with current selection\n");
        }
    }
    else
    {
        printf("\nFalse Selection, please re-select\n");
    }
}

void generateRandom()
{
    for (int i = 0; i < 20; i++)
    {
        fundInterestRateArr[i] = rand() % (8 + 1 - 3) + 3;
    }
}

void changeCal()
{
    float noteSizesArr[11] = {1000.00, 500.00, 100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25};

    for (int i = 0; i < 11; i++)
    {
        printf("\n%.2f Majikite  x%d ", noteSizesArr[i], (int)floor(change / noteSizesArr[i]));
        change = fmod(change, noteSizesArr[i]);
    }
    printf("\n");
}

void bestCase(float money, int month)
{
    float currentAmountOnFund, currentAmountOnBank;
    if (month >= 60)
    {
        if (money >= bestSum && month == 60)
        {
            bestSum = money;
        }
        return;
    }

    currentAmountOnFund = 3 * (((fundInterestRateArr[month / 3]) * money) / 100.00);
    currentAmountOnBank = 6 * (BankInterestRate / 100) * money;

    bestCase(money + currentAmountOnFund, month + 3);
    bestCase(money + currentAmountOnBank, month + 6);
}

void showHistory()
{
    printf("\nHere's your selection history: \n");
    for (int i = 1; i <= 20; i++)
    {
        int monthParse = i * 3;
        if (decisionHistoryArr[i] == 1)
            printf("%d years %d months: Fund\n", monthParse / 12, monthParse % 12);
        else if (decisionHistoryArr[i] == 2)
            printf("%d years %d months: Bank\n", monthParse / 12, monthParse % 12);
    }
}

int main()
{
    generateRandom();
    bestCase(currentMoney, 0);
    printf("Start Money: %.2f Majikite\n", currentMoney);
    printf("\n");

    while (monthPass < 60)
    {
        anouncement();
        if (currentSelection == 2)
        {
            interestAnouncement(fundInterestRateArr[(monthPass - 3) / 3], monthPass - 3.00);
            interestAnouncement(fundInterestRateArr[monthPass / 3], monthPass);
        }
        else if (currentSelection == 1)
        {
            interestAnouncement(fundInterestRateArr[monthPass / 3], monthPass);
        }
        questions();
    }

    printf("Final Money: %.2f Majikite", currentMoney);
    change = currentMoney;

    changeCal();
    showHistory();

    printf("\nBest Case: %.2f\n", bestSum);
    return 0;
}
