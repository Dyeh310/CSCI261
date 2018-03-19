/* Author: Nicholas Heyd
   Project 5
   Displays various values
   depending on date selected
   Csci 261, Spring 2018 */

#include <iostream>
#include <string>
using namespace std;

void testMenu ();
//prints the user interface

bool isLeapYear (int year);
//enter a year integer value
//if the year is divisble 400 OR the year is divisble by 4 and year not divisble by 100
//returns a boolean value of true if it is a leap year or false if it is not

int getCenturyValue (int year);
//enter a year interger value
//take the first two digits of the year, divide by 4, save the reminder. Subtract remainder from 3, multiply by 2
//returns the century's value as an integer

int getYearValue (int year);
//enter a year integer value
//store the last two digits of the year. Factor in leap years. divide the value of years by 4 (discard remainder). Add the two results together.
//For example, 2008: (8/4) = 2, return 2 + 8 = 10
//returns the year value as an integer

int getMonthValue (int month, int year);
//takes month and year value as an integer.
//tests if the year value is a leap year. if it IS, Jan returns 6, and Feb returns 2.
//if it is NOT a leap year: Jan-0, Feb-3, Mar-3, Apr-6, May-1, June-4, Jul-6, Aug-2, Sep-5, Oct-0, Nov-3, Dec-5
//returns the month's value

int dayOfWeek (int month, int day, int year);
//takes a month, day, year value as an integer
//compute the sum of the date's day, plus getMonthValue(), plus getYearValu(), and getCenturyValue.
//Divide the sum  by 7 and compute the remainder. Remainder == 0 (Sunday), Remainder == 1(Monday), etc.

bool properYearInput (int year);
//takes the year as an int value
//if the year is later than 1582 (1583+) then return true
//else return false

bool properMonthInput (int month);
//takes the month as an int value
//if the month is between 1 - 12 then return true
//else return false

bool checkDayInput (int year, int month, int day);
//takes year, month, and day as inputs
//checks to see if the year is a leap year
//checks how many days in that month
//if the day input correctly matches both
//returns true if it does, returns false if it doesnt

std::string dayOfWeek (int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a std::. If day has
// value 0, then Sunday is returned; 1, then Monday is returned; and so on.


int main () {

	int choice;
	int day, month, year;

	do {
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice) {
		case 1: // check if a given year is leap year
			cout << "Please enter a year: ";
			cin >> year;
			if (properYearInput(year) == false) break; //year > 1582 check
			if (isLeapYear(year)){
				cout << "Year " << year << " is a leap year" << endl;
			} else {
				cout << "Year " << year << " is NOT a leap year" << endl;
			}
			break;

		case 2: // calculate the century value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			if (properYearInput(year) == false) break; //year > 1582 check
			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;

		case 3: // calculate the year value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			if (properYearInput(year) == false) break; //year > 1582 check
			cout << "The year value is: " << getYearValue(year) << endl;
			break;

		case 4: // calculate the month value of a given month in a given year
			cout << "Please enter a year and month: ";
			cin >> year >> month;
			if (properYearInput(year) == false) break; //year > 1582 check
			if (properMonthInput(month) == false) break; // month == 1-12 check
			cout << "The month value is: " << getMonthValue(month, year) << endl;
			break;

		case 5: // calculate the day of week of a given date
			cout << "Please enter a year, a month, and a day: ";
			cin >> year >> month >> day;
			if (properYearInput(year) == false) break; //year > 1582 check
			if (properMonthInput(month) == false) break; // month == 1-12 check
			if (checkDayInput(year, month, day) == false) break; //checks if it is a valid day
			cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
			break;

		case 6: // print out the name of a given day of the week 
			cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
			cin >> day;
			cout << "The name of the day of the week is: " << dayOfWeek(day) << endl;
			break;

		case 7:
			cout << "Did you test all functions yet? If not, please rerun the program\n";
			break;

		default:
			cout << "Wrong opition. Please choose from menu\n";
			break;
		}

		system("pause");

	} while (choice != 7);

}

void testMenu () {
	cout << "*************************************" << endl;
	cout << "* Test Menu *" << endl;
	cout << "* 1. isLeapYear *" << endl;
	cout << "* 2. getCenturyValue *" << endl;
	cout << "* 3. getYearValue *" << endl;
	cout << "* 4. getMonthValue *" << endl;
	cout << "* 5. dayOfWeek(month, day, year) *" << endl;
	cout << "* 6. dayOfWeek(day) *" << endl;
	cout << "* 7. Quit *" << endl;
	cout << "*************************************" << endl;
}

bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int getCenturyValue(int year) {
	int answer;
	int remainder;
	remainder = (year / 100) % 4;
	answer = (3 - remainder) * 2;
	
	return answer;
}

int getYearValue(int year) {
	int answer;
	int lastTwo;
	int timesDivided;

	lastTwo = year % 100;
	timesDivided = lastTwo / 4;
	answer = lastTwo + timesDivided;

	return answer;
}

int getMonthValue(int month, int year) {
	switch (month) {
	case 1: //January
		if (isLeapYear(year)) {
			return 6;
		}
		else {
			return 0;
		}
		break;
	
	case 2: //February
		if (isLeapYear(year)) {
			return 2;
		}
		else {
			return 3;
		}
		break;
	
	case 3: //March
		return 3;
		break;
	
	case 4: //April
		return 6;
		break;

	case 5: //May
		return 1;
		break;

	case 6: //June
		return 4;
		break;

	case 7: //July
		return 6;
		break;

	case 8: //August
		return 2;
		break;

	case 9: //September
		return 5;
		break;

	case 10: //October
		return 0;
		break;

	case 11: //November
		return 3;
		break;

	case 12: //December
		return 5;
		break;

	default:
		return -1;
		break;
	}//switch end
}

int dayOfWeek (int month, int day, int year) {
	int sum;
	int remainder;
	sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	remainder = sum % 7;
	switch (remainder){
		case 0: //Sunday
			return 0;
			break;
		case 1: //Monday
			return 1;
			break;
		case 2: //Tuesday
			return 2;
			break;
		case 3: //Wednesday
			return 3;
			break;
		case 4: //Thursday
			return 4;
			break;
		case 5: //Friday
			return 5;
			break;
		case 6: //Saturday
			return 6;
			break;
		default:
			cout << "Please enter valid values." << endl;
	}

}

bool properYearInput (int year) {
	if (year > 1582){
		return true;
	} else {
		cout << "Please enter a year greater than 1582" << endl;
		return false;
	}
}

bool properMonthInput (int month) {
	if (month >= 1 && month <= 12){
		return true;
	} else {
		cout << "Please enter a month value between 1 and 12." << endl;
		return false;
	}
}

bool checkDayInput (int year, int month, int day){
	if (day <= 28 && properMonthInput(month)==true && properYearInput(year) == true){
		return true;
	} else if (day == 29 && isLeapYear(year) == true && month == 2){
		return true;
	} else if (day <= 30 && ((month > 2 && month <= 12) || month == 1)){
		return true;
	} else if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
		return true;
	} else {
		cout << "Please enter a valid year, month, and day" << endl;
		return false;
	}
}

std::string dayOfWeek (int day) {
	switch (day){
		case 0: //Sunday
			return "SUNDAY";
			break;
		case 1: //Monday
			return "MONDAY";
			break;
		case 2: //Tuesday
			return "TUESDAY";
			break;
		case 3: //Wednesday
			return "WEDNESDAY";
			break;
		case 4: //Thursday
			return "THURSDAY";
			break;
		case 5: //Friday
			return "FRIDAY";
			break;
		case 6: //Saturday
			return "SATURDAY";
			break;
		default:
			return "Please enter a value between 0-6";

	}
}





