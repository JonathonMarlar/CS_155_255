/*******************************************************************************
Cole Marlar
CS 255
Assignment #4
Description:	Encode and decode a series of messages via vigenere cipher
********************************************************************************/
#include <iostream>
#include "cipher.h"
using namespace std;

int getChoice();										// also prints a nice menu
void doChoice(int, string, cipher &);					// does whatever the user chooses to do
string openPrompt(string prompt, string input);			// prompts the user for input

int main() {
	cipher newCipher;
	string input;

	int choice = getChoice();

	while (choice > 0) {
		doChoice(choice, input, newCipher);
		choice = getChoice();
	}

	system("PAUSE"); // remove or change to synonimous function(s) in other OSs
	return 0;
}

/*****************************************************************
FUNCTION:		getChoice
PURPOSE:		Inputs a choice from the user; also displays a menu
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The user's option
******************************************************************/
int getChoice() {
	int choice;

	cout << "********************************************************************" << endl;
	cout << "                VIGENERE CIPHERS: ENCODING AND DECODING             " << endl;
	cout << "********************************************************************" << endl;
	cout << " 1) Enter a new keyphrase"	<< endl;
	cout << " 2) Convert a plaintext phrase to cipher text" << endl;
	cout << " 3) Convert a  typed ciphered message to plaintext" << endl;
	cout << " 4) Convert a ciphered message stored in the object to plaintext" << endl;
	cout << " 5) Display both plaintext and ciphered messages" << endl;
	cout << " 0) Exit program" << endl;
	cout << "--------------------------------------------------------------------" << endl;

	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

/*****************************************************************
FUNCTION:		doChoice
PURPOSE:		Executes the user's chosen option
INCOMING:		the user's choice, the keyphrase to change to, and
				the memory address of a cipher object
OUTGOING:		The values changed by the mutator functions of
				the cipher object
RETURN:			N/A
******************************************************************/
void doChoice(int choice, string input, cipher & myCipher) {
	switch(choice) {
		case 1: {
			input = openPrompt("Enter a new keyword: ",input);
			myCipher.newKey(input);
		} break;

		case 2: {
			input = openPrompt("Enter the plaintext to be converted into ciphered text: ",input);
			cout << "Your encoded message is " << myCipher.encipher(input) << endl;
		} break;

		case 3: {
			input = openPrompt("Enter the ciphered text to be converted into plaintext: ",input);
			cout << "Your decoded message is " << myCipher.decipher(input) << endl;
		} break;

		// decode a message stored in the object
		case 4: {
			system("CLS"); // remove or change to equivalent on other OSs
			cout << "Your decoded message is " << myCipher.decipher(myCipher.getCiphertext()) << endl;
		} break;

		// Display both plaintext and ciphered messages
		case 5: {
			system("CLS"); // remove or change to equivalent on other OSs
			cout << "Your enciphred text:  " << myCipher.getCiphertext() << endl;
			cout << "Your deciphered text: " << myCipher.getPlaintext() << endl;
		} break;

		default: {
			system("CLS"); // remove or change to equivalent on other OSs
			cout << "The option you selected is invalid. Please try again." << endl;
		}
	}
}

/*****************************************************************
FUNCTION:		openPrompt
PURPOSE:		Prompts the user for a string of input and returns
				it
INCOMING:		the prompt string, input variable
OUTGOING:		N/A
RETURN:			The user's input as a string
******************************************************************/
string openPrompt(string prompt, string input) {
	system("CLS"); // remove or change to equivalent on other OSs
	cin.get();

	cout << prompt;
	getline(cin,input);
	
	return input;
}
