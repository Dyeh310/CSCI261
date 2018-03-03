/* Author: NMH
   Project 4
   This program calculates temperature
   and displays it in both Celsius
   and Fahrenheit
   Csci 261, Spring 2018 */

#include <iostream>
#include <string>
using namespace std;

	//FUNCTION DECLARTIONS


	void print_introduction();
	//prints out information to tell the user what this program does.

	double celsius_at_depth (double depth);
	//computes and returns the celsius temperature at a depth measured in kilometers.

	double celsius_to_fahrenheit (double celsius);
	//converts a Celsius temperature to Fahrenheit 

	void print_conclusion (double depth);
	//displays the conclusion of both Celsius and Fahrenheit at the depth of the earth


int main () {

	int depth = 0;
	string goOn = "";
	bool running = true;
	bool againCheck = true;


	//1. print introduction
	print_introduction();

	while (running) {
	againCheck = true;
	//2.ask user to enter depth
	cout << "Enter a depth in KM: " << endl;

	//3. get user's input
	cin >> depth;

	//4. print out the conclusion
	print_conclusion (depth);

	//5. ask user if he/she wants to continue
	cout << "Would you like to do it again? (Y/N): " << endl;

	//6. get user's input
		while (againCheck){
		cin >> goOn;

		//7. repeat
		if (goOn == "y" || goOn == "Y"){
			running = true;
			againCheck = false;
		} else if (goOn == "n" || goOn == "N") {
		//8. exit program
			running = false;
			againCheck = false;
		} else {
			cout << "Invalid entry. (Y/N)" << endl;
		}
		}
	}





}


	//FUNCTIONS

	void print_introduction() {
		cout << "Hello! The program will tell you the temperature of the earth at any depth." << endl;
	}

	double celsius_at_depth (double depth) {
		double celsius = 0;

		celsius = (10 * depth) + 20;
		return (celsius);
	}

	double celsius_to_fahrenheit (double celsius) {
		double fahrenheit = 0.0;

		fahrenheit = (1.8 * celsius) + 32;
		return (fahrenheit);
	}

	void print_conclusion (double depth) {
		double celsius = 0;
		double fahrenheit = 0;

		celsius = celsius_at_depth(depth);
		fahrenheit = celsius_to_fahrenheit(celsius);
		
		cout << "The temperate of the earth at a depth of " << depth 
			<< " KM is " << celsius << " in Celsius, and " << fahrenheit 
			<< " in Fahrenheit." << endl;
	}


