/*
Author: Alexandrea Teigeler
Date Last Modified: June 5th, 2021
Program Details:
				This program will take information from the user to see how
				their portfolio might perform given the amount of money they
				save based on interest and the time given for that intest
				to grow. Also shows the benefits and value of making a monthly
				deposit to help the total interest and capital grow exponetinally
				faster than without it.
				----------------------------------------------------------------
				Program will print a blank menu, then it will prompt user for input
				------------------------------------------------------------------
				After input, two reports will display using the input from the user
				This input will display End of year balance for each year
				It will display the End of year interest Earned
				-----------------------------------------------------------------
				After displaying the report, the program will repeat and allow
				user to play around with the input values until they choose to quit
				and exit the program
				-----------------------------------------------------------------
				The try-catch, do-while block statements are used to make sure that
				any input that can not be recognized will not cause the program to 
				crash and will continually prompt user for the correct type of
				input
*/
#include "Investment.h"

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


int main() {
	
	Investment banking;

	//temp variables to be used when assigning class objects with values
	double money;
	double interest;
	int years;
	int user_choice = 0;
	//used for the do-while, do-try-catch-while blocks to catch wrong input from user
	bool correct_Menu_select = false;

	do {
	
		banking.MenuPrint();
		cout << "********************************" << endl;
		cout << "***********Data Input***********" << endl;
		cout << "================================" << endl;
		cout << "Initial Investment Amount: ";
		
		
		//Try block to check if user input the allowed menu options
		//will catch anything that isn't a double/integer
		do {
			try {
				std::cin >> money;
				cout << "--------------------------------" << endl;

				//To catch error if userChoice gets input that IS NOT an integer
				//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
					cout << "Unknown Entry. Please Try Again." << endl;

					correct_Menu_select = false;

					cout << "Initial Investment Amount: ";
					std::cin >> money;
				}
				if (money >= 0) {
					//Passes the try test
					//Makes sure the user entered a POSITIVE integer
					//exits the do-while
					correct_Menu_select = true;
				}
				else {
					throw (money);

				}
			}
			catch (...) {
				correct_Menu_select = false;
				cout << "Please Enter a positive integer." << endl;

			}
		} while (correct_Menu_select == false);


		banking.SetInvestmentAmount(money);
		cout << "Monthly Deposit: ";
		
		

		//Try block to check if user input the allowed menu options
		//will catch anything that isn't a double/integer
		do {
			try {
				std::cin >> money;
				cout << "--------------------------------" << endl;

				//To catch error if userChoice gets input that IS NOT an integer
				//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
					cout << "Unknown Entry. Please Try Again." << endl;

					correct_Menu_select = false;

					cout << "Monthly Deposit: ";
					std::cin >> money;
					cout << "--------------------------------" << endl;
				}
				if (money >= 0) {
					//Passes the try test
					//Makes sure the user entered a POSITIVE integer
					//exits the do-while
					correct_Menu_select = true;
				}
				else {
					throw (money);

				}
			}
			catch (...) {
				correct_Menu_select = false;
				cout << "Please Enter a positive integer." << endl;

			}
		} while (correct_Menu_select == false);


		banking.SetMonthlyDeposit(money);
		cout << "Annual Interest: %";
		

		//Try block to check if user input the allowed menu options
		//will catch anything that isn't a double/integer
		do {
			try {
				std::cin >> interest;
				cout << "--------------------------------" << endl;
				//To catch error if userChoice gets input that IS NOT an integer
				//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
					cout << "Unknown Entry. Please Try Again." << endl;

					correct_Menu_select = false;

					cout << "Annual Interest: %";
					std::cin >> interest;
					cout << "--------------------------------" << endl;
				}
				if (interest >= 0) {
					//Passes the try test
					//Makes sure the user entered a POSITIVE integer
					//exits the do-while
					correct_Menu_select = true;
				}
				else {
					throw (interest);

				}
			}
			catch (...) {
				correct_Menu_select = false;
				cout << "Please Enter a positive integer." << endl;

			}
		} while (correct_Menu_select == false);


		banking.SetInterestRate(interest);
		cout << "Number of years: ";
		
		
		//Try block to check if user input the allowed menu options
		//will catch anything that isn't a double/integer
		do {
			try {
				std::cin >> years;
				cout << "================================" << endl;

				//To catch error if userChoice gets input that IS NOT an integer
				//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
					cout << "Unknown Entry. Please Try Again." << endl;

					correct_Menu_select = false;

					cout << "Number of years: ";
					std::cin >> years;
					cout << "================================" << endl;
				}
				if (years >= 0) {
					//Passes the try test
					//Makes sure the user entered a POSITIVE integer
					//exits the do-while
					correct_Menu_select = true;
				}
				else {
					throw (years);

				}
			}
			catch (...) {
				correct_Menu_select = false;
				cout << "Please Enter a positive integer." << endl;

			}
		} while (correct_Menu_select == false);

		banking.SetNumYears(years);
		cout << endl;
		cout << endl;
		

		//Prints out reports from information provided
		banking.PrintReport();

		//prompt user to continue or exit the program
		user_choice = banking.ProgramControl();
	}while (user_choice == 0); //if not 0, will exit and close program
	cout << "**********************************Program Closing************************************" << endl;
	cout << endl;
	cout << "Thank you for using AirGead Banking Fiscal Responsibility Interactive Banking System." << endl;
	cout << endl;
	cout << "*************************************************************************************" << endl;

};