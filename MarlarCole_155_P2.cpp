/**********************************************************
Cole Marlar
Project 2
Allows the user to choose what to do and calls the correct
function to do that action.
Due: October 31, 2011
***********************************************************/

#include <iostream>
#include <string>
using namespace std;
//constants
const string STARS = "********************************";

//**********************************************************
//Function Prototypes
//**********************************************************
void PrintLabel(string name);
bool IsNumeric(string strVal);
void PrintAscii(char beg, char end);
string StrCat(string str1, string str2, string str3);
void PrintBox(int dim);
void SeparateString(string orig, string& one, string& two, string& three);
int AddNums(string strNum);

int GetChoice();

//**********************************************************
//Driver Program
//**********************************************************
int main(){
    int choice = GetChoice();
   
    while(choice !=0){
        system("cls");
        cout << STARS << endl;
        if(choice == 1){
            PrintLabel("Cole Marlar");
        }
        else if (choice == 2){
            string strInput;
            cout << "Enter a string and the program will tell you if all values are numeric values" << endl;
            cin >> strInput;
            bool Ans = IsNumeric(strInput);
			cout << Ans << endl;
        }

        else if (choice == 3){
            char one, two;
            cout << "Enter 2 characters and the function will print " << endl;
            cin >> one >> two;
            PrintAscii(one, two);
            
        }

        else if (choice == 4){
            string str1, str2, str3;

            cout << "Enter the first string" << endl;
            cin >> str1;
            cout << "Enter the second string" << endl;
            cin >> str2;
            cout << "Enter the third string" << endl;
            cin >> str3;

            cout << StrCat(str1, str2, str3) << endl;
           
        }
        else if (choice == 5){
             int dimension;
             cout << "Please enter one value to represent the row and column dimension" << endl;
             cin >> dimension;
             PrintBox(dimension);    
        }
        else if (choice == 6){
             string orig, str1, str2, str3;
             cout << "Enter a three strings of characters, separated by commas (no whitespace)" << endl;
             cin >> orig;
             SeparateString(orig, str1, str2, str3);
			 cout << str1 << endl << str2 << endl << str3 << endl;
        }
        else if (choice == 7){
             string str;
             cout << "Enter a string with only numeric values (test for strings with non-numeric)" << endl;
             cin >> str;
             cout << AddNums(str) << endl; 
        }
       
        cout << STARS << endl;
        choice = GetChoice();    //call to get next choice
        system("cls");
    } // end while loop
    return 0;
} 
//**********************************************************
//Function:  PrintLabel
//Purpose:   This function should print the parameter
//			 inside two lines of your favorite character
//Incoming:  name contains the string to be printed
//Outgoing:	 N/A
//Return:	 N/A
//**********************************************************
void PrintLabel(string name){
	// prints my name
	cout << name << endl;
}



//**********************************************************
//Function:	 IsNumeric
//Purpose:	 This function takes in a string and returns
//			 true if all characters are numeric ['0'..'9']
//Incoming:  strVal contains the characters to be tested
//Outgoing:  N/A
//Return:    Returns true if all values are numeric, returns
//           false otherwise
//**********************************************************
bool IsNumeric(string strVal){
	bool result = true;
	// it checks to see if there are ANY chars in the string
	for (char x='A'; x<='z'; x++) {
		int charFind = strVal.find(x);
		// if it finds a letter AT ALL, the result is false
		if (charFind>-1)
			result = false;
	}
	return result;
}


//**********************************************************
//Function:  PrintAscii
//Purpose:   This function takes in a two characters.  It  
//			 prints in the format of char:ASCIIVal.  It 
//           prints all chars from the first parameter to
//           the second parameter
//Incoming:  beg is the first character to be printed
//           end is the last character to be printed
//Outgoing:  N/A
//Return:    N/A
//**********************************************************
void PrintAscii(char beg, char end){
	// if the first character is bigger in ASCII, print the chars between them
	if (beg<end) {
		for (char x = beg; x <= end; x++)
			cout << x << ":" << int(x) << endl;
	}
	// if the last character is larger in ASCII, then this code prints the chars in between
	// this is a fallback in case the user enters two letters in the order like "z A"
	else {
		for (char x = end; x <= beg; x++)
			cout << x << ":" << int(x) << endl;
	}
}

//**********************************************************
//Function:  StrCat
//Purpose:   This function takes in three strings 
//           The three substrings will be concatenated,
//           separated by colons, and a new string returned
//Incoming:  str1: 1st string
//           str2: 2nd string 
//           str3: 3rd string
//Outgoing:  N/A
//Return:    Concatenated strings separated by colons
//**********************************************************
string StrCat(string str1, string str2, string str3){
       string result;

	   // connects the strings, separated by a colon
	   result = str1 + ":" + str2 + ":" + str3;

       return result;       
}

//**********************************************************
//Function:  PrintBox
//Purpose:   This function prints a triangle in the form
//				XXXXXX
//				XXOOOX
//				XOXOOX
//				XOOX0X
//				X00X0X
//				XXXXXX
//           EX: dim = 6
//			 based upon the dimension given
//Incoming:  One val representing row and column dimension 
//Outgoing:  N/A
//Return:    N/A
//**********************************************************
void PrintBox(int dim){
	
	for (int row=1; row<=dim; row++) {
		for (int col=1; col<=dim; col++) {
			// prints an X if row # is 1 or equal to dim
			if ( row==1 || row==dim )
				cout << "X";
			// prints an X if col # is 1 or equal to dim
			else if ( col==1 || col==dim )
				cout << "X";
			// prints an X if row & col are equal to each other
			else if ( row == col )
				cout << "X";
			// prints an O everywhere else
			else cout << "O";
		}
		// prints a blank line
		cout << endl;
	}
	
}

//**********************************************************
//Function:  Separate String
//Purpose:   This function takes the first parameter, which
//           contains two commas, and divides the original
//           string into three strings (the last three
//           parameters)
//Incoming:  orig contains a string divided into three parts
//           by two commas.  one, two, three contain no
//           meaningful data
//Outgoing:  the last three parameters will contain the 
//           string substrings from the original string
//Return:    N/A
//**********************************************************
void SeparateString(string orig, string& one, string& two, string& three){
	
	int lenStr1 = orig.find(","); // length of first string
	one = orig.substr(0, lenStr1); // sets the first string
	// finds the second comma for calculations
	int lenStr2 = orig.find(",", lenStr1+1);
	// sets the second string, starting from the end of the first string
	two = orig.substr(lenStr1+1, lenStr2-(lenStr1+1));
	int lenFullStr = orig.length(); // length of the full string
	// sets the last string
	three = orig.substr(lenStr2+1, lenFullStr-lenStr2);

}

//**********************************************************
//Function:  AddNums
//Purpose:   This function takes in a string of characters
//           The function will verify all characters are 
//           numeric.  The function will return 0 is any of
//           the characters are non-numeric.  The function
//           will return the sum of the digits if the 
//           characters are numeric.
//Incoming:  string of supposed, numeric data 
//Outgoing:  N/A
//Return:    sum of numeric characters
//**********************************************************
int AddNums(string strNum){
    int result = 0;	
	
	if (IsNumeric(strNum)) {
		int numLength = strNum.length();
		// check each character to see what number it is
		for (int i = 0; i <= numLength; i++) {
			// find the character
			string n = strNum.substr(i, 1);
			// check to see which one it is and then add the appropriate value
			if (n == "0") result += 0;
			else if (n == "1") result += 1;
			else if (n == "2") result += 2;
			else if (n == "3") result += 3;
			else if (n == "4") result += 4;
			else if (n == "5") result += 5;
			else if (n == "6") result += 6;
			else if (n == "7") result += 7;
			else if (n == "8") result += 8;
			else if (n == "9") result += 9;
		}
	}

	return result;
}

//**********************************************************
//Function:  GetChoice
//Purpose:   This function prompts the user for their choice
//Incoming:  N/A
//Outgoing:  N/A
//Return:    Menu choice
//**********************************************************
int GetChoice(){
	cout << endl << STARS << endl;
	cout << "Enter your choice " << endl;
	int option;


    cout << "1.  Print Label" << endl;
	cout << "2.  Is Numeric" << endl;
	cout << "3.  Print Ascii" << endl;
	cout << "4.  String concatenation" << endl;
	cout << "5.  Print Box" << endl;
	cout << "6.  Separate String" << endl;
	cout << "7.  Add Nums" << endl;
	cout << "0.  Quit" << endl;
	cout << STARS<< endl << endl;
	cin >> option;
	
	return option;
}