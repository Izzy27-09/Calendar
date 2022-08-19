#include <cmath>
#include<iostream>
#include<cctype>
class Date {
private:
	int month, day, year;
	char yn;//used to ask if user wants to use the info inputed
	std::string weekday[7] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
	std::string fpt = "Carl";
public:
	//Constructor that sets date to January 1st 1753
	Date() {
		month = 1;
		day = 1;
		year = 1753;
	}
	void DayCal() {
		int mon, y, c, w, tempy;
		tempy = year;//hold year tempoarily so original will not be tampered with
		if (month > 2)
			mon = month;
		else {
			mon = month + 12;//done to get month code for January and Feburary as theirs are 13 and 14
			tempy--;//decrease the year for months January and February
		}
		y = tempy % 100;//done to get the last 2 digits of year
		c = tempy / 100;//done to get the first 2 digits of year
		//Zellers Algorithm used to find the day given a date
		w = (day + floor((13 * (mon + 1)) / 5) + tempy + floor(tempy / 4) + floor(c / 4) + (5 * c));
		//done to get the index for simple array above
		w = w % 7;
	}//end of DayCal

	//Acessors:
	int GetMonth() {
		return month;
	}
	int GetYear() {
		return year;
	}
	int GetDay() {
		return day;
	}
	//Mutators
	void SetYear() {
		yn = NULL;
		while (yn != 'y') {
			std::cout << "Please enter a year  ";
			std::cin >> year;
			std::cout << "\n Are you sure? enter y for yes ";
			std::cin >> yn;
			tolower(yn);
		}
		
	}
	void SetMonth() {
		yn = NULL;
		while (yn != 'y') {
			std::cout << "\nPlease enter the month in integer form  ";
			std::cin >> month;
			while ((month <= 0) || (month > 12)) {
				std::cout << "Invaild month entered, try again ";
				std::cin >> month;
			}
			std::cout << "\n Are you sure? enter y for yes ";
			std::cin >> yn;
			tolower(yn);
		}
	}
	void SetDay() {
		std::cout << "\nPlease enter the day of the month  ";
		std::cin >> day;
		if (year % 4 == 0) {
			if (month == 2) {
				while ((day <= 0) || (day > 29)) {
					std::cout << "Invalid Day entered,try again\n ";
					std::cin >> day;
				}
			}
		}//if statement meant to deal with leap years
		else {
			if (month == 2)
				while ((day <= 0) || (day > 28)) {
					std::cout << "Please enter a vaild day\n";
					std::cin >> day;
			    }// end of while dealing with February
			else if((month==4)||(month==6)||(month==9)||(month==11))
				while ((day <= 0) || (day > 30)) {
					std::cout << "Please enter a valid day";
					std::cin >> day;
				}//end of while dealing with months with 30 days
			else
				while ((day <= 0) || (day > 31)) {
					std::cout << "Please enter a valid day";
					std::cin >> day;
				}//end of while dealing with months with 31 days
		}
		


	}
	void SetDate() {
		SetYear();
		SetMonth();
		SetYear();
	}
};//end of class