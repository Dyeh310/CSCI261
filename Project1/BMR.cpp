/* Author: NMH
   Project 2
   This program implements
   the Harris-Benedict equation.
   Csci 261, Spring 2018 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {

	//Variables
	string gender = "";
	string endOrNot = "";
	bool running = true;
	bool goodbyeCheck = true;
	int weight = 0;
	int height = 0;
	int age = 0;
	int caloriesInChocolate = 230;
	double BMR = 0;
	double totalChocolateCalories = 0;

	cout << "Welcome to my BMR calculator." << endl;

	//Main program loop
	while (running) {
		goodbyeCheck = true; //Reset this variable each time the program loops so the final loop will run properly
		//Checks the gender of the user
		while (!(gender == "m" || gender == "f")){
			cout << "Gender (M or F): " << endl;
			cin >> gender;
			std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower); //Turns the input to lowercase to trim down the if statement
			if (!(gender == "m" || gender == "f")) {
				cout << "Wrong gender input. Please enter again. ";
			}
		}//Ends gender check

			cout << "Weight (in pounds): " << endl;
			cin >> weight;
			cout << "Height (in inches): ";
			cin >> height;
			cout << "Age (in years): ";
			cin >> age;

			//Prints the proper BMR and that amount in calories converted to chocolate bars according to the user's sex.
			if (gender == "m"){
				BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
				totalChocolateCalories = BMR / caloriesInChocolate;
				cout << "He needs " << BMR << " calories to maintain his weight." << endl;
				cout << "That is about " << totalChocolateCalories << " chcolate bar's calories." << endl;
			} else if (gender == "f") {
				BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
				totalChocolateCalories = BMR / caloriesInChocolate;
				cout << "She needs " << BMR << " calories to maintain her weight." << endl;
				cout << "That is about " << totalChocolateCalories << " chcolate bar's calories." << endl;
			}

			//Checks if the user would like to run the program again.
			while (goodbyeCheck) {
			cout << "Do you want to do another calculation? (Y/N): " << endl;
			cin >> endOrNot;
			std::transform(endOrNot.begin(), endOrNot.end(), endOrNot.begin(), ::tolower); //Change the string to lowercase to trim the if statement
			if (endOrNot == "n") { //Add  something for error handling.
				goodbyeCheck = false;
				running = false;
			} else if (endOrNot == "y") {
				gender = ""; //reset the gender variable so the gender while loop works properly.
				running = true;
				goodbyeCheck = false;
			}

		}
	}
		cout << "Thanks for using my BMR calculator. Good bye!" << endl;
		return 0;
	}

	
