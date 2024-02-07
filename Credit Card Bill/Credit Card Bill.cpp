// Credit Card Bill.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
    This program takes as input the billing amount on a credit card statement and the amount of payment
    made on the bill. It then determines the amount of credit applied to the account (if the bill has been
    paid in full) or the penalty amount and remaining balance (if the bill has not been paid in full). The
    amount of the penalty is based on the percentage of payment to billing amount. The program then
    displays the credit or the penalty amount and remaining balance on the bill (including the added penalty
    if any).
*/
#include <iostream>
using namespace std;

const double fixedCredit = 10;
const double creditPercentage = .01;
const double maxPenaltyPercentage = .2;
const double midPenaltyPercentage = .1;
const double lowPenaltyPercentage = .05;
const double midPenaltyLow = .2;
const double midPenaltyHigh = .5;

int main()
{
    double balance, payment, credit=0, penalty = 0;
    cout << "Enter the current balance and payment amount: ";
    cin >> balance >> payment;

    if (balance - payment <= 0)
    {
        credit = balance * creditPercentage;
        if (credit > 10)
            credit = 10;
    }
    else if (payment / balance >= midPenaltyHigh)
        penalty = (balance - payment) * lowPenaltyPercentage;
    else if (payment / balance < midPenaltyLow)
        penalty = (balance - payment) * maxPenaltyPercentage;
    else
        penalty = (balance - payment) * midPenaltyPercentage;

    if (penalty > 0)
    {
        cout << "You have a penalty of $" << penalty << endl;
        cout << "Remaming balance = $" << balance - payment + penalty;
    }
    else
        cout << "You have a credit of $" << credit << endl;
}


