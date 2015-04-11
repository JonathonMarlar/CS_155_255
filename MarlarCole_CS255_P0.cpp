// Jonathon Cole Marlar
// CS 255 Spring 2012
// Assignment: Project 0
// Description: This program allows the user to input KPH or the time
// 				to walk one mile and converts it to MPH.
#include <iostream>
#define NDEBUG
#include <cassert>
using namespace std;

const int SCREENWIDTH = 80;

void drawLine(char symbol);
char displayMenu();

double getSpeedKPH();
void getPace(int& minutes, int& seconds);

double convertToMPH(int minutes, int seconds);
double convertToMPH(double speedKPH);

// -------------------------------------------------------------------
int main() {
	char selection = '?';
	int minutes = 0;
	int seconds = 0;
	double speed = 0;
	
	// set output of number to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	do
	{
		selection = displayMenu();
		switch (selection)
		{
			case 'P' : {
				getPace(minutes, seconds);
				speed = convertToMPH(minutes, seconds);
				cout << "Your speed is " << speed << " MPH." << endl;
			} break;
			case 'S' : {
				speed = getSpeedKPH();
				speed = convertToMPH(speed);
				cout << "Your speed is " << speed << " MPH." << endl;
			} break;
			case 'X' : break;
			default : cout << "Invalid choice, please try again." << endl;
		}
	} while (selection != 'X');
	
	// system("PAUSE");
	return 0;
}

/**************************************************
FUNCTION:		drawLine
DESCRIPTON:		Draws a character symbol SCREENWIDTH
				amount of times
INCOMING:		The character to draw
OUTGOING:		N/A
RETURN:			N/A
***************************************************/
void drawLine(char symbol) {
	for (int i=0; i<SCREENWIDTH; i++)
		cout << symbol;
	cout << endl;
}

/**************************************************
FUNCTION:		displayMenu
DESCRIPTON:		Draws a menu on the screen and allows
				the user to input his/her choice
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The user's input
***************************************************/
char displayMenu() {
	char choice;
	
	drawLine('*');
	
	// display a simple list of menu options via cout
	cout << "--CHOOSE AN OPTION--" << endl;
	cout << "P: Convert pace, in minutes and seconds, to MPH" << endl;
	cout << "S: Convert speed in KPH to MPH" << endl;
	cout << "X: End the program" << endl;
	
	drawLine('*');
	
	// prompt & input from user
	cout << "Enter your choice: ";
	cin >> choice;
	
	return choice;
}

/**************************************************
FUNCTION:		getSpeedKPH
DESCRIPTON:		Lets the user enter the speed in
				KPH and returns it if valid
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The speed in KPH
***************************************************/
double getSpeedKPH() {
	system("cls");
	double speed=0;
	
	do {
		// prompt & input
		cout << "Enter the speed (in KPH) to convert: ";
		cin >> speed;
	} while (speed <= 0); // make sure the speed is valid
	
	return speed;
}

/**************************************************
FUNCTION:		getPace
DESCRIPTON:		Prompts the user to enter a value
				in minutes and seconds the amount
				of time to go one mile
INCOMING:		N/A
OUTGOING:		Minutes, seconds
RETURN:			N/A
***************************************************/
void getPace(int& minutes, int& seconds) {
	system("cls");
    
	do {
		// prompt the user for input
		cout << "Enter the number of minutes and seconds, separated by a space: ";
		cin >> minutes >> seconds;
	// loop to prevent the user from dividing by 0 in convertToMPH(int, int)
	} while ((minutes + seconds == 0) || (minutes < 0 && seconds < 0)); // check to see if it's valid
}

/**************************************************
FUNCTION:		convertToMPH
DESCRIPTON:		Converts the amount of time to walk
				one mile to MPH
INCOMING:		Minutes, seconds
OUTGOING:		N/A
RETURN:			MPH
***************************************************/
double convertToMPH(int minutes, int seconds) {	
	double mph = 0;
	
	// convert min & sec to double for precision
	mph = 60 / (double(minutes) + (double(seconds) / 60));
	
	return mph;
}

/**************************************************
FUNCTION:		convertToMPH
DESCRIPTON:		Converts KPH to MPH
INCOMING:		The speed in KPH
OUTGOING:		N/A
RETURN:			MPH
***************************************************/
double convertToMPH(double speedKPH) {
	double mph = 0;
	
	// 1 mi = 1.6 km, thus the simple equation
	mph = speedKPH / 1.6;
	
	return mph;
}
