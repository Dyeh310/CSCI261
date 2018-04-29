/*
	CSCI 261: PROJECT 8
	
	This program will ask the user to enter a sequence of scores between 0 and 100, inclusive.
	The program then will print out the stats about these scores, including:
		the number of scores
		the maximum score
		the minimum score and average score
	If there are no scores enter, the output message shall just say that there is no score.

	Author: Nicholas Heyd

*/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


void get_scores(vector<int> &v);
//get integer scores from keyboard and store in v.
//we assume that the user will input scores in range
//of 0 to 100, inclusive. User enter a negative
//number to stop the input and end the function

void print_stats(vector<int> &v);
//print out the stats of data that are stored in v
//includes: max, min, total number of data,
//and the average

bool is_palindrome (string sentence);
//return true if the sentence is a palindrome
//false otherwise

int main ()
{


	vector<int> v; //used to contain the scores
	char answer; //used to contain "repeat" answer.
	
	get_scores(v);

	//Repeat Problem 1
	while (true)
	{
		cin >> answer;
		if (answer == 'n' || answer == 'N')
		{
			break;
		}
		else if (answer == 'Y' || answer == 'y')
		{
			get_scores(v); //call the function get scores again (essentially restarting Problem 1)
		}
		else 
		{
		cout << "Please enter a Y or N" << endl;	
		}
	}



	string sentence; //C-string variable

	while (true) 
	{
		
		cout << "Enter a sentence: " << endl;
		cin.ignore(); //clears the input stream since both getline and cin are being used
		getline(cin, sentence); //takes the original sentence
		string original = sentence; //keeps the original input
		if (is_palindrome(sentence) == true)
		{
			cout << "\"" << original << "\"" << " is a palindrome" << endl;
		}
		else 
		{
			cout << "\"" << original << "\"" << " is not a palindrome" << endl;
		}

		cout << "Do you want to try another sentence Y/N:" << endl;
		cin >> answer; //answer to repeat or not
		if (answer == 'n' || answer == 'N')
		{
			break; //break out of the loop and end the program
		}
		else if (answer == 'Y' || answer == 'y')
		{
			continue; //perform another iteration of the loop
		}
	}


}

void get_scores(vector<int> &v)
{
	int input = 0;
	v.clear();

		cout << "Enter scores, enter -1 to stop:" << endl;
		while (input >= 0)
		{
			cin >> input;
			if (input >= 0 && input <= 100)
			{
				v.push_back(input); //adds the input to the vector as long as it meets the criteria
			}		
		} 

		if (v.empty() == false){
			print_stats(v); //calls the print function
		} else {
			cout << "There are no scores." << endl;
			cout << "Do you want to try another set of scores? Y/N" << endl;
		}
}

void print_stats(vector<int> &v)
{
//print out the stats of data that are stored in v
//includes: max, min, total number of data,
//and the average

	int min = v[0];
	int max = 0;
	int sum = 0;
	double average = 0;
	int totalNumber = v.size(); //size of the vector

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i]; //takes min value of scores
			}
			if (v[i] > max)
			{
				max = v[i]; //takes max value of scores
			}
			sum += v[i]; //every score is added into the sum variable
		}
	
		average = static_cast<double>(sum)/totalNumber; //averages the score.
	
		cout << "There are a total of " << totalNumber << endl;
		cout << "The highest score is: " << max << endl;
		cout << "The lowest score is: " << min << endl;
		cout << "The average score is: " << average << endl; 
		cout << "Do you want to try another set of scores? Y/N" << endl;

}

bool is_palindrome (string sentence)
{
	bool answer = false; //always start the boolean as false
	sentence.erase(remove_if(sentence.begin(), sentence.end(), isspace), sentence.end());//removes all spaces
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);//changes sentence to all lower case
	string rev = sentence; // will be used to hold the inverted sentence.



	reverse(rev.begin(), rev.end()); //invert the sentence.

	if (sentence.compare(rev) == 0) //if the sentence backwards is the same as forwards...
	{
		answer = true; // then it is a palindrome
	}

	return answer; //if it isnt, returns false
}


