/*
	Robert Giglio III
	11/14/2016

	Tic-Tac-Toe
	Exercise 3
*/

#include<iostream>
#include<string>
using namespace std;

void instructions();
void showBoard();
int changeTurn(char);
void chooseSquare(char[], char, int);
bool isGameOver();

static char gameBoard[9] = { '1' ,'2','3','4','5','6', '7','8','9'};
static int turn = 0;
static int flag = 0;

int main()
{
	
	char player[2];
	int choice = NULL;

	instructions();
	cout << "Player 1, would you like to go first? (y/n): ";
	cin >> player[0];
	if (player[0] == 'y')
	{
		turn = 2;
		player[0] = 'X';
		player[1] = 'O';
	}
	else
	{
		turn = 1;
		player[0] = 'O';
		player[1] = 'X';
	}
	
	while (!isGameOver())
	{
		showBoard();
		changeTurn(player[(turn -1)]);
		cout << "\nPlayer " << turn << ", Which square will you take? ";
		cin >> choice;
		if(choice >= 1 && choice <= 9)
		{
			chooseSquare(gameBoard, player[(turn - 1)], choice);
		}
		if (isGameOver())
			break;
	}
	showBoard();
	if (flag == 1)
		cout << "\nPlayer " << turn << " wins!" << endl;
	else
		cout << "\nCat's Game!" << endl;

	cout << "\n\nThank you for playing" << endl;

	system("pause");
	return 0;
}

void instructions()
{
	cout << "\t\tThe rules are simple" << endl;
	cout << "Each player is trying to prevent thier opponent from placing" << endl;
	cout << "\tthree of their game pieces (either 'X' or 'O') in a row." << endl;
	cout << "\nTo win, you must get three of your games pieces in a row" << endl;
	cout << "\teither vertically, horizontally, or diagonally." << endl;
	cout << "\nIf neither player is able to get three in a row" << endl;
	cout << "\tthen it's a 'Cat's Game'!" << endl;
	cout << "\n\t\t  Good luck!\n" << endl;
}

void showBoard()
{
	cout << "\n\t\tHere's the board:" << endl;
	cout << "\n\n\t\t---------------";
	cout << "\n\t\t| " << gameBoard[0] << " |  " << gameBoard[1] << " |  " << gameBoard[2] << " | " << endl;
	cout << "\t\t---------------";
	cout << "\n\t\t| " << gameBoard[3] << " |  " << gameBoard[4] << " |  " << gameBoard[5] << " | " << endl;
	cout << "\t\t---------------";
	cout << "\n\t\t| " << gameBoard[6] << " |  " << gameBoard[7] << " |  " << gameBoard[8] << " | " << endl;
	cout << "\t\t---------------" << endl;

}

int changeTurn(char player)
{
	if ((player == 'X' && turn == 1) || (player == 'O' && turn == 1))
		turn++;
	else if ((player == 'O' && turn == 2) || (player == 'X' && turn == 2))
		turn--;
	
	return turn;
}

void chooseSquare(char gameBoard[], char player, int choice)
{

	if (gameBoard[(choice - 1)] == 'X' || gameBoard[(choice - 1)] == 'O')
		cout << "That space is already occupied. Please choose another square." << endl;
	else
	{
		gameBoard[(choice - 1)] = player;
	}
}

bool isGameOver()
{
	if ((gameBoard[0] == gameBoard[1] == gameBoard[2]) || (gameBoard[3] == gameBoard[4] == gameBoard[5]) || (gameBoard[6] == gameBoard[7] == gameBoard[8]) || (gameBoard[0] == gameBoard[3] == gameBoard[6]) || (gameBoard[1] == gameBoard[4] == gameBoard[7]) || (gameBoard[2] == gameBoard[5] == gameBoard[8]) || (gameBoard[0] == gameBoard[4] == gameBoard[8]) || (gameBoard[2] == gameBoard[4] == gameBoard[6]))
	{
		flag = 1;
		return true;
	}
	if ((gameBoard[0] == 'X' || gameBoard[0] == 'O') && (gameBoard[1] == 'X' || gameBoard[1] == 'O') && (gameBoard[2] == 'X' || gameBoard[2] == 'O') && (gameBoard[3] == 'X' || gameBoard[3] == 'O') && (gameBoard[4] == 'X' || gameBoard[4] == 'O') && (gameBoard[5] == 'X' || gameBoard[5] == 'O') && (gameBoard[6] == 'X' || gameBoard[6] == 'O') && (gameBoard[7] == 'X' || gameBoard[7] == 'O') && (gameBoard[8] == 'X' || gameBoard[8] == 'O'))
		return true;
	else
		return false;
}