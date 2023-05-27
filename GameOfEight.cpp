#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

#define endl '\n'

/*
The Game of Eight

------------------

The game of 8 is played by 2 players. 
The game starts with the initial number 8 (from here on refered to as the initial number). 
The first player will choose a number from 1 to 3 
(from here on refered to as the chosen number). 
If the player inputs something outside of the 1 to 3 range 
it should be an error and the player must choose again. 
The initial number is subtracted by the chosen number. 
Then the next player's turn happens. 
The next player cannot choose the number that the last player chose. 
If the initial number goes to 0 on your turn, then you win. 
Otherwise if the number goes below 0, your opponent wins. 
The player should always see what choices are available to him when 
prompted to enter his choice. After the game is over, the user should be prompted whether 
they want to play again.

Write a program to solve this problem.


2 player -> two varibale
we need to a variable that stores the initial number
we need to a variable that stores the upperbound number
we need to a variable that stores the lowerbound number
we need to a varibale that stores current choose number
we need to a varibale that stores previous choose number

*/

const int IGNORE_CHARS = 256,
		  UPPER_BOUND = 3,
		  LOWER_BOUND = 1,
		  DEFAULT_SCORE = 8,
		  PLAYER_ONE = 1,
		  PLAYER_TWO = 2;

void PlayGame();
bool WantToPlayAgain();

int GetNumber();
int GetPlayerTurn(int playerTurn);

bool IsGameOver(int initialNumber);

void DisplayResult(int playerTurn, int initialNumber);	

int main() {
	
	do {
		system("CLS");
		PlayGame();
	} while (WantToPlayAgain());
	
	return 0;
}

void PlayGame() {
	int initialNumber = DEFAULT_SCORE,
		chosenNumber = 0,
		previousChosenNumber = 0,
		playerTurn = PLAYER_ONE;
		
	cout << "The range of the number from 1 to 3" << endl;
		
	do {
		
		cout << "\n----- Current Number: ( " << initialNumber << " ) -----" << endl;
		
		cout << ">>>>> Player " << playerTurn << " <<<<<" << endl;
		
		previousChosenNumber = chosenNumber;
		
		if (previousChosenNumber != 0) {
			cout << "The previous number was: " << previousChosenNumber << endl;			
		}
		
		chosenNumber = GetNumber();
		
		if (previousChosenNumber == chosenNumber) {
			cout << "Please enter different the prvious number ( " << previousChosenNumber << " )" << endl;				
		}
		
		if (chosenNumber < 1 || chosenNumber > 3) {
			cout << "Please enter the number from 1 to 3!" << endl;
		} else {
			if (previousChosenNumber != chosenNumber)  {
				initialNumber -= chosenNumber;
				previousChosenNumber = chosenNumber;
				playerTurn = GetPlayerTurn(playerTurn);
			}
		}	
		cout << ">>>>>>>>>>>>> <<<<<<<" << endl;
		
	} while (!IsGameOver(initialNumber));	
	
	DisplayResult(playerTurn, initialNumber);	
}

int GetPlayerTurn(int playerTurn) {
	return playerTurn == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
}

void DisplayResult(int playerTurn, int initialNumber) {
	
	cout << "****Result****" << endl;
	
	if (initialNumber == 0) {
		if (playerTurn == PLAYER_ONE) {
			cout << "Congratulation the player " << PLAYER_TWO << " is the winner !" << endl;
			cout << "It's fine the player " << PLAYER_ONE << " is not the winner !" << endl;
		} else {
			cout << "Congratulation the player " << PLAYER_ONE << " is the winner !" << endl;
			cout << "It's fine the player " << PLAYER_TWO << " is not the winner !" << endl;
		}
	}
	
	if (initialNumber < 0) {
		if (playerTurn == PLAYER_ONE) {
			cout << "Congratulation the player " << PLAYER_ONE << " is the winner !" << endl;
			cout << "It's fine the player " << PLAYER_TWO << " is not the winner !" << endl;
		} else {
			cout << "Congratulation the player " << PLAYER_TWO << " is the winner !" << endl;
			cout << "It's fine the player " << PLAYER_ONE << " is not the winner !" << endl;
		}
	}	
}

int GetNumber() {
	int number;
	bool failure;
	
	do {
		cout << "Please enter the number you want: ";
		cin >> number;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			failure = true;
			cout << "Error Input! Please Try Again!" << endl;
		}
		
	} while (failure);
	
	return number;
}

bool IsGameOver(int initialNumber) {
	return initialNumber <= 0;
}

bool WantToPlayAgain() {
	
	char input;
	bool failure;
	
	do {
		failure = false;
		
		cout << "Do you want to play again? ";
		cin >> input;
		
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			failure = true;
			cout << "Error Input! Please Try Again!" << endl;
		} else {
			cin.ignore(IGNORE_CHARS, '\n');
			
			input = tolower(input);
		}
		
	} while (failure);
	
	return input == 'y';
}


