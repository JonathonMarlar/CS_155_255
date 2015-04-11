#include "cipher.h"
#include <cmath>

cipher::cipher() {
	// set variables to safe values
	keyword 			= " ";
	plainText 			= " ";
	cipherText			= " ";
}

/*****************************************************************
FUNCTION:		newKey
PURPOSE:		Sets a keyphrase to cipher a message
INCOMING:		the keyphrase to change to
OUTGOING:		N/A
RETURN:			N/A
******************************************************************/
void cipher::newKey(string keyPhrase) {
	string kp;

	// check for valid letters (skip spaces and capitalize where necessary)
	for (unsigned int i = 0; i < keyPhrase.length(); i++) {
		keyPhrase[i] = toupper(keyPhrase[i]);
		if ( keyPhrase[i] >= 'A' && keyPhrase[i] <= 'Z' )
			kp += keyPhrase[i];
	}

	keyword = kp;
}

/*****************************************************************
FUNCTION:		encipher
PURPOSE:		Encrypts a message via vigenere cipher
INCOMING:		The message to be encoded
OUTGOING:		N/A
RETURN:			The enciphered message
******************************************************************/
string cipher::encipher(string message) {	
	char addtoMes;						// changes the value of the letter to its cipher equivalent
	unsigned int keyLetter = 0;			// counter for looping back to the start of the keyword
	
	for ( unsigned int i = 0; i < message.length(); i++ ) {
		message[i] = toupper(message[i]);
		
		if ( message[i] >= 'A' && message[i] <= 'Z' ) {
			addtoMes = keyword[keyLetter] - 'A';
			message[i] += addtoMes;
			keyLetter++;
			
			// Some of the math may cause the chars to go beyond 'Z'. Subtracting 26 loops it back
			if ( message[i] > 'Z' )
				message[i] -= 26;
				
			// if we reach the end of the keyword, loop back
			if ( keyLetter >= keyword.length() )
				keyLetter = 0;
		}
	}
	
	cipherText = message;
	return cipherText;
}

/*****************************************************************
FUNCTION:		decipher
PURPOSE:		Decodes a cipher message into plaintext
INCOMING:		The encoded message
OUTGOING:		N/A
RETURN:			The message in plaintext
******************************************************************/
string cipher::decipher(string message) {
	char addtoMes;						// changes the value of the letter to its plaintext equivalent
	unsigned int keyLetter = 0;			// counter for looping back to the start of the keyword
	
	for ( unsigned int i = 0; i < message.length(); i++ ) {
		message[i] = toupper(message[i]);
		
		if ( message[i] >= 'A' && message[i] <= 'Z' ) {
			// there are 26 letters in the alphabet, ergo the need to increment 26 for a valid
			addtoMes = (message[i] + 26) - keyword[keyLetter];
			message[i] = 'A' + addtoMes;
			keyLetter++;

			// Some of the math may cause the chars to go beyond 'Z'. Subtracting 26 loops it back
			if ( message[i] > 'Z' )
				message[i] -= 26;
				
			// if we reach the end of the keyword, loop back
			if ( keyLetter >= keyword.length() )
				keyLetter = 0;
		}
	}
	
	plainText = message;
	return plainText;
}

/*****************************************************************
FUNCTION:		getPlaintext
PURPOSE:		Returns the value of the plaintext data member
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			plaintext data member
******************************************************************/
string cipher::getPlaintext() const {
	return plainText;
}

/*****************************************************************
FUNCTION:		getCiphertext
PURPOSE:		Returns the value of the ciphered data member
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The ciphered message
******************************************************************/
string cipher::getCiphertext() const {
	return cipherText;
}
