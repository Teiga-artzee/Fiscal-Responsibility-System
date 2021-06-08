/*
Author: Alexandrea Teigeler
Date Last Modified: June 5th, 2021
Program Details:
				Class header file for investment banking at AirGead
				Handles the initializations of functions
				---------------------------------------
				Handles the initializations and definitions of the 'Get' functions
				--------------------------------------
				Private variables only to be accessed by the appropriate class objects and functions
	
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
	public:
		Investment(); //default constructor
		
		//sets class objects with value
		void SetInvestmentAmount(double money);
		void SetMonthlyDeposit(double money);
		void SetNumYears(int years);
		void SetInterestRate(double interest);

		//prints information to the console
		void MenuPrint();
		void PrintReport();

		//retreives the class objects values
		double GetInterest() {return interest_Rate;};
		double GetInvestAmount() {return initial_Invest_Amount;};
		double GetMonthDeposit() {return monthly_Deposit;};
		double GetAnnualInterest() {return annual_Interest;};
		int GetYears() {return num_Years;};

		//controls whether the user continues using program
		//or decides to exit the program
		int ProgramControl();
		


	private:
		double interest_Rate;
		double initial_Invest_Amount;
		double monthly_Deposit;
		double annual_Interest;
		int num_Years;



};

#endif
