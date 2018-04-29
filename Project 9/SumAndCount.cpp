/*

Author: Nicholas Heyd
CSCI 261 Project 9: Recursion Functions
Purpose: Take a number, and give the sum of all numbers, including that number, and,
	     count the number of characters within a C-string.
Started:   4/22/18
Finished:  4/28/18

*/

#include <iostream>
#include <string>


using namespace std;


int sum (int n);
//precondition: enter a positive integer
//postcondition: return the sum off all numbers leading to, and the given number
	
int str_length(char s[]);
//precondition: enter a sentence in the form of a char array
//postcondition: outputs a numeric value, including white spaces, of the number of chars in the array

int main ()
{
	bool running = true; //used to control the main loop

	while (running)
	{

		char answer; //holds the answer to repeating the program or not
		char s[100]; //hold the sentence 
		int n; //holds a positive integer

		cout << "Enter a positive integer: " << endl;
		cin >> n; //takes the number for sum function

		cout << "The sum of 1+2+...+" << n << " is: " << sum(n) << endl;


		cout << "Enter a sentence: " << endl;
		cin.ignore(); //used to clear the input buffer since cin and getline are both used
		cin.getline(s,100); //takes a sentence for the str_length function

		cout << "It contains " << str_length(s) << " chars, including white spaces\n" << endl;

		cout << "Do you want to have another run? Y/N: " << endl;

		while (true) //inner while loop used to determine if the user would like to run the program again. pressing n terminates the program
			{
				cin >> answer;
				tolower(answer); //convert the answer to lower case
				if (answer == 'y')
				{
					break;
				} else if (answer == 'n') 
				{
					running = false;
					break;
				} else 
				{
					cout << "Please enter a y or n" << endl;
			}
		}

		
	}
}


int sum (int n)
{
	int result = 0; //initialze

	if (n <= 0) //if the integer is 0 or less, simply returns a 0
	{
		return result;
	} else
	{
		result = n + sum(n-1);
	}



}

int str_length (char s[])
{
	int length = 0;
	if (s[length] == '\0') //program stops when it finds the null character
	{
		return 0;
	} else 
	{
		return str_length(s+1)+1; //must add one in order to not cause an overflow
	}
}
