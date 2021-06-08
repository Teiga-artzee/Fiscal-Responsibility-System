/*
Author: Alexandrea Teigeler
Date Last Modified: June 5th, 2021
Program Details:
				Program handles all the class functions
				---------------------------------------
				Default constructor is used in case the user does not set any value
				---------------------------------------
				Menu Print will print base menu with no values to display
				---------------------------------------
				Set Functions assign class objects with values from the user input given in main.cpp
				---------------------------------------
				Print report shows the potential growth the user could have by saving money
				---------------------------------------
				Program Control allows user to continue by pressing 0 or to exit by choosing a different number
				Will continue to prompt for input if user inputs anything but a positive integer
				

*/
#include "Investment.h"

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

Investment::Investment() {
	//default constructor
	initial_Invest_Amount = 0;
	monthly_Deposit = 0;
	annual_Interest = 0;
	interest_Rate = 0;
	num_Years = 0;

};



void Investment::MenuPrint() {
	//default menuPrint
	cout << "         *AirGead Banking*      " << endl;
	cout << "      Fiscal Responsibility     " << endl;
	cout << "   Interactive Banking System   " << endl;
	cout << "********************************" << endl;
	cout << "***********Data Input***********" << endl;
	cout << "================================" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "--------------------------------" << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "--------------------------------" << endl;
	cout << "Annual Interest: " << endl;
	cout << "--------------------------------" << endl;
	cout << "Number of years: " << endl;
	cout << "================================" << endl;
	
	cout << endl;
	cout << endl;

};

//Sets the class objects with values for initial deposit, montly depoist, interest rate, and years
void Investment::SetInvestmentAmount(double money) {initial_Invest_Amount = money;};

void Investment::SetMonthlyDeposit(double money) {monthly_Deposit = money;};

void Investment::SetInterestRate(double interest) {interest_Rate = interest;};

void Investment::SetNumYears(int years) {num_Years = years;};

//Prints to console the report of how the users portfolio will grow given the amount of savings, interest rate, and time left to grow
void Investment::PrintReport() {

	//temp variables
	double endYearTotal = this->GetInvestAmount(); //also used for year end balanace statement in for loop
	double month_Depo = this->GetMonthDeposit();
	double endYearEarned = 0.00; //Interest gained

	//variables that shouldn't change once initialized
	int years = this->GetYears();
	int months;
	int interest = this->GetInterest();

	//set amount of months determined by amount of years given
	months = years * 12;

	//prints the header of the Report
	if (month_Depo == 0) {
		cout << endl;
		cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "================================================================" << endl;
		cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
		cout << "----------------------------------------------------------------" << endl;
	}
	else {
		cout << endl;
		cout << "       Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "================================================================" << endl;
		cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
		cout << "----------------------------------------------------------------" << endl;
	}

	//Runs through program calculations the amount of years (converted to months) user input
	for (int i = 0; i <= months; i++) {
		//calculations of interest, principle, and total growth
		endYearTotal += month_Depo;
		endYearEarned = (endYearTotal) * ((interest / 100.0) / 12.0);
		endYearTotal += endYearEarned;

		//tempt int used to control the amount of times the report actually prints to console
		int tempInt = i / 12;
		if (i % 12 == 0 & i >= 12) {
			//should only print num of years

			cout << "   " << tempInt << ":" << endl;
			cout << setprecision(2) << fixed << "                    $" << setw(20) << left << endYearTotal;
			cout << setprecision(2) << fixed << setw(10) << right << "$" << endYearEarned << endl;
			cout << endl;
			cout << "----------------------------------------------------------------" << endl;
		}

	}
	cout << "================================================================" << endl;
	cout << endl;
	
};



int Investment::ProgramControl() {
	//If the user presses 0, the program will repeat
	//if the user enters any other number, the program exits
	int tempInt = 0;
	bool correct_Menu_select = false;
	cout << "Press 0 to enter in new values to try different banking scenerios." << endl;
	cout << "Press ANY other number to exit the program." << endl;

	
	//Try block to check if user input the allowed menu options
	//will catch anything that isn't a double/integer
	do {
		try {
			std::cin >> tempInt;

			//To catch error if userChoice gets input that IS NOT an integer
			//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
				cout << "Unknown Entry. Please Try Again." << endl;

				std::cin >> tempInt;
			}
			if (tempInt >= 0) {
				//Passes the try test
				//Makes sure the user entered a POSITIVE integer
				//exits the do-while
				correct_Menu_select = true;
			}
			else {
				throw (tempInt);

			}
		}
		catch (...) {
			cout << "Please Enter a positive integer." << endl;

		}
	} while (correct_Menu_select == false);

	
	if (tempInt == 0) { return 0; }
	else { return 2; }
};