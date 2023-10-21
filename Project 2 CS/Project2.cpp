/*
 * Project2.cpp
 *
 *  Date: 9/30/2023
 *  Author: Christian Tran
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

class BankAccount {
private:
    double initialBalance;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

public:
    BankAccount(double initialBalance, double monthlyDeposit, double annualInterestRate, int years)
        : initialBalance(initialBalance), monthlyDeposit(monthlyDeposit), annualInterestRate(annualInterestRate), years(years) {}

    void calculateAndDisplayBalances() {
        double openingAmount = initialBalance;
        double total = initialBalance;  // Include initial balance in the total
        double monthlyInterestRate = annualInterestRate / 12 / 100;

        std::cout << std::left << std::setw(7) << "Month" << std::setw(18) << "Opening Amount" << std::setw(18) << "Deposited Amount" << std::setw(12) << "Total" << std::setw(12) << "Interest" << std::setw(18) << "Closing Balance" << std::endl;
        std::cout << "----------------------------------------------------------------------------------" << std::endl;

        for (int month = 1; month <= years * 12; ++month) {
            double interest = (openingAmount + monthlyDeposit) * monthlyInterestRate;
            double closingBalance = openingAmount + monthlyDeposit + interest;

            std::cout << std::left << std::setw(7) << month << std::fixed << std::setprecision(2)
                << std::setw(18) << openingAmount << std::setw(18) << monthlyDeposit << std::setw(12) << (openingAmount + monthlyDeposit) << std::setw(12) << interest << std::setw(18) << closingBalance << std::endl;

            openingAmount = closingBalance;
            total += monthlyDeposit;  // Update the total with the deposited amount
        }
    }
};

double getValidDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= 0) {
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a non-negative number." << std::endl;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    }
    return value;
}

int main() {
    std::cout << "Welcome to Airgead Banking Investment Calculator!" << std::endl;

    double initialBalance = getValidDoubleInput("Enter initial investment amount in dollars: ");
    double monthlyDeposit = getValidDoubleInput("Enter monthly deposit amount in dollars: ");
    double annualInterestRate = getValidDoubleInput("Enter annual interest rate (%): ");
    int years = static_cast<int>(getValidDoubleInput("Enter number of years to calculate: "));

    BankAccount account(initialBalance, monthlyDeposit, annualInterestRate, years);

    std::cout << "\nCalculating Investment Growth..." << std::endl;

    std::cout << "\nMonth-by-Month Investment Summary:\n";
    account.calculateAndDisplayBalances();

    return 0;
}
