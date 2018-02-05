/* Author: Nicholas Heyd
   Project 3
   This program implements
   plays the game 23.
   Csci 261, Spring 2018 */

#include <iostream>
#include <string>
using namespace std;

int main () {

	//Variables and loopp controls
	int toothpicksLeft = 23; //toothpick counter used throughout the game.
	int playerChoice = 0;
	int computerChoice = 0;
	string goOn = "";
	bool outterRunning = true;
	bool innerRunning = true;
	bool playerChoiceRunning = true;
	bool tryAgain = true;

	while (outterRunning){
	toothpicksLeft = 23;
	cout << "Let's play the game of \"23\"!" << endl;


		while (innerRunning){
		playerChoiceRunning = true; //turns on player loop after restart or computer's turn.
		tryAgain = true; //ensures that if the game ends, the option to continue is switched on.

		cout << "Enter the number of sticks you wish to pick: " << endl;
		while (playerChoiceRunning) {//starts the player's turn
			cin >> playerChoice;
			if (playerChoice > 3 || playerChoice < 1){
				cout << "Wrong number of sticks. Please pick 1,2, or 3 sticks: " << endl;
			} else if (playerChoice <= toothpicksLeft) {
				toothpicksLeft -= playerChoice;
				cout << "You picked " << playerChoice << " stick. " << toothpicksLeft << " left " << endl;
				playerChoiceRunning = false; //End's player's turn, switching to the computer's turn

				//Check to see if player loses.
				if (toothpicksLeft <= 0){
					cout << "You picked the last stick" << endl;
					cout << "Sorry the computer beat you" << endl;
					playerChoiceRunning = false;//ends player's turn
					innerRunning = false;//Since the game is over, the game switches to the outter (main) loop, asking if the player wants to play again.
				}

				
			} else if (playerChoice >= toothpicksLeft) {
				cout << "There arent enough sticks!" << endl;//Added this incase the player tries to cheat!
			}
		}//end player's turn loop

		//Computer Turn
		if (toothpicksLeft > 0 ){//if the toothpick's are empty, the computer skips its turn, since the player has already lost.
			if (toothpicksLeft > 4) {
				computerChoice = 4 - playerChoice;
			} else if (toothpicksLeft >= 2 && toothpicksLeft <= 4){
				if (toothpicksLeft == 2){
					computerChoice = 1;
				} else if (toothpicksLeft == 3){
					computerChoice = 2;
				} else if (toothpicksLeft == 4){
					computerChoice == 3;
				}
			} else if (toothpicksLeft == 1){
				computerChoice == 1;
			}
			toothpicksLeft -= computerChoice;
			cout << "Computer picked " << computerChoice << " sticks. " << toothpicksLeft << " left" << endl;
			if (toothpicksLeft > 0) {
				cout << "Your turn. "; //Computer's friendly way of
			}
			//Check 
			if (toothpicksLeft <= 0){
				cout << "The computer picked the last stick! You won!!!" << endl; 	
				innerRunning = false;
			}
		}

		}//end inner game loop

		cout << "Do you want to play another game?: " << endl;
		while (tryAgain){
			cin >> goOn;
			if (goOn == "y"){
				innerRunning = true; //restarts the game
				tryAgain = false;//exits this loop and returns to the start of the program.
			} else if (goOn == "n") {
				outterRunning = false;//exits the main loop, effectively ending the game
				tryAgain = false;//exits this loop
			} else {
				cout << "Please enter y/n" << endl;
			}
		}
	}//end outter game loop

	return 0;
}
