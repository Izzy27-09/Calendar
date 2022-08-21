#include <cmath>
#include<iostream>
#include<cctype>
class Date {
private:
	int month, day, year,w;
	char yn;//used to ask if user wants to use the info inputed
	std::string weekday[7] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };
public:
	//Constructor that sets date to January 1st 1753
	Date() {
		month = 1;
		day = 1;
		year = 1753;
		yn = NULL;
		w = 0;
	}
	void DayCal() {
		int mon, y, c, tempy;
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
		std::cout << weekday[w]; std::cout << ","; std::cout << GetMonth(); std::cout << " "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
	}//end of DayCal
	void ExactDate() {
		switch (month)
		{
		case 1:
			std::cout << weekday[w]; std::cout <<",January, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 2:
			std::cout << weekday[w]; std::cout << ",February, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 3:
			std::cout << weekday[w]; std::cout << ",March, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 4:
			std::cout << weekday[w]; std::cout << ",April, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 5:
			std::cout << weekday[w]; std::cout << ",May, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 6:
			std::cout << weekday[w]; std::cout << ",June, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 7:
			std::cout << weekday[w]; std::cout << ",July, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 8:
			std::cout << weekday[w]; std::cout << ",August, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 9:
			std::cout << weekday[w]; std::cout << ",September, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 10:
			std::cout << weekday[w]; std::cout << ",October, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 11:
			std::cout << weekday[w]; std::cout << ",November, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		case 12:
			std::cout << weekday[w]; std::cout << ",December, "; std::cout << GetDay(); std::cout << ","; std::cout << GetYear();
			break;
		}
	}

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
			yn=tolower(yn);
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
			yn=tolower(yn);
		}
	}
	void SetDay() {
		yn = NULL;
		while (yn != 'y'){
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
				else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
					while ((day <= 0) || (day > 30)) {
						std::cout << "Please enter a valid day ";
						std::cin >> day;
					}//end of while dealing with months with 30 days
				else
					while ((day <= 0) || (day > 31)) {
						std::cout << "Please enter a valid day ";
						std::cin >> day;
					}//end of while dealing with months with 31 days
			}
			std::cout << "Are you sure this is what you want to input?, Enter y for yes\n";
			std::cin >> yn; yn = tolower(yn);

		}//
		
		


	}
	void SetDate() {
		SetYear();
		SetMonth();
		SetYear();
	}
};//end of class
