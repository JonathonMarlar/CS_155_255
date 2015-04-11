#ifndef CIPHER_H
#define CIPHER_H

#include <string>
using namespace std;

class cipher {
public:
	cipher();
	void newKey(string keyPhrase);			// changes the keyphrase to encode the text
	string encipher(string message);		// encode a message
	string decipher(string message);		// decode a message
	string getPlaintext() const;			// returns the plaintext
	string getCiphertext() const;			// returns the ciphertext
	
private:
	string keyword;
	string plainText;
	string cipherText;
};

#endif
