/*********************************************************************
Cole Marlar
Project 3
This program simulates a vending machine. The user can input the
amount of money and the item he/she wants. The program will output
the amount of change and the amount of quarters, nickels, and dimes
returned.
Due: November 10, 2011
**********************************************************************/
#include <iostream>
using namespace std;

int InputChange(); // does calculations regarding input of money
void DrawMenu(); // a handy menu that draws all of the choices
void FigureChange(int,int); // this prints out the exact change

int main() {
	int cents; // the amount of money the user puts in
	int choice=0; // the choice the user wants to make

	DrawMenu();
	cents=InputChange();

	// keep looping until the user enters 0 for change
	while (cents>0) {
		// prompt & input for the choice
		cout << "Enter the value of the item you want: ";
		cin >> choice;

		// if the choice the user inputs is correct, figure out the change accordingly
		if (choice==45 || choice==50 || choice==75 || choice==100)
			FigureChange(cents, choice);
		// otherwise print an error
		else {
				system("cls");
				cout << "Invalid option. Please try again." << endl;
				cout << "Your money has been returned." << endl << endl;
				DrawMenu();
		}
		cents=InputChange();
	}

	return 0;
}

/***************************************************************
FUNCTION:	InputChange
PURPOSE:	Allows the user to input the change. Prints an error
			and restarts the loop if it is not divisible by 5.
INCOMING:	N/A
OUTGOING:	N/A
RETURN:		the amount of change entered by the user
****************************************************************/

int InputChange() {
	int change;
	int counter=0; // lets it loop until the correct change is added.

	// loop this part in order to make sure the change is divisible by 5
	while (counter<1) {
		// promt & input for the change
		cout << "Enter the amount of change you want: ";
		cin >> change;
		// if it's divisible by 5 and falls within the limit, quit the loop and return the change
		if (change%5==0 && change>=0 && change<=100)
			counter++;
		// otherwise print an error
		else {
			system("cls");
			cout << "Invalid -- please keep the change divisible by 5 or within the range (0-100]." << endl << endl;
			DrawMenu();
		}
	}

	return change;
}

/***************************************************************
FUNCTION:	DrawMenu
PURPOSE:	Draws a handy-dandy menu that shows all of the
			items & prices on the screen.
INCOMING:	N/A
OUTGOING:	N/A
RETURN:		N/A
****************************************************************/
void DrawMenu() {
	cout << "*******************************************************" << endl;
	cout << "*****             Vending Machine                 *****" << endl;
	cout << "*****   Twix Candy Bar.................45 Cents   *****" << endl;
	cout << "*****   Reese's Cup....................50 Cents   *****" << endl;
	cout << "*****   Nature Valley Bar..............75 Cents   *****" << endl;
	cout << "*****   RC Cola........................100 Cents  *****" << endl;
	cout << "*****            Enter 0 change to exit           *****" << endl;
	cout << "*******************************************************" << endl;
}

/***************************************************************
FUNCTION:	FigureChange
PURPOSE:	Calculates the amount of change to return to the user.
INCOMING:	The money and the price of the item
OUTGOING:	N/A
RETURN:		N/A
****************************************************************/
void FigureChange(int money, int itemPrice) {
	int quarters=0, dimes=0, nickels=0;

	// if the user has enough money for the item
	if (money>=itemPrice) {
		int change=money-itemPrice;
		system("cls"); // clear screen

		// prints the total change back
		cout << "Your total combined change is " << change << " cents." << endl << endl;

		// Loop & count how much change to give to the user
		while(change>0) {
			// check for quarters
			if (change-25>-1) {
				quarters+=1;
				change-=25;
			}
			// else check for dimes
			else if (change-10>-1) {
				dimes+=1;
				change-=10;
			}
			// else check for nickels
			else {
				nickels+=1;
				change-=5;
			}
		}

		// prints out how many quarters, dimes and nickels the user gets back.
		cout << "Your change includes " << quarters << " quarter(s), " << dimes << " dime(s), and " << nickels << " nickel(s)." << endl << endl;
		DrawMenu();

	}

	// otherwise print an error and give the user his/her money back
	else {
		system("cls");
		cout << "You do not have enough money to buy this item." << endl;
		cout << "Your change has been returned." << endl;
		DrawMenu();
	}
}