/******************************************************
Cole Marlar
Project 4
This program reads a list of names from two different
files and allows the user to read files and combine the
two lists onto one file.
22 November 2011
*******************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// this function will allow the user to input a choice
int GetChoice();
// this function will read a file and set the items into an array
int ReadFile(string namelist[]);
// this function will print the contents of the array
void PrintArray(string namelist[], int size);
// this function will be used in Merge() to verify that the names are in alphabetical order
bool CheckValues(string namelist[], int size);
// this function will put the two lists onto one file
void Merge(string names1[], string names2[], int size1, int size2);
// this function will print the contents of a user-specified file
void PrintFileContents();

const int MAX = 10;

int main() {
	
	int option = GetChoice(); // what the user's option is
	string namelist1[MAX]; // the first list
	string namelist2[MAX]; // the second list
	int size1 = 0; // the size of the first array
	int size2 = 0; // the size of the second array

	// until the user enters 0, do the appropriate task according to the user's input
	while (!option==0) {
		switch (option) {
			case 1: {
				system("cls");
				// read the number of items in a list
				size1 = ReadFile(namelist1);
				// print how many items were recorded
				cout << "A total of " << size1 << " items have been saved." << endl << endl;
			} break;

			case 2: {
				system("cls");
				// read the number of items in a list
				size2 = ReadFile(namelist2);
				// print how many items were recorded
				cout << "A total of " << size2 << " items have been saved." << endl << endl;
			} break;
			
			case 3: {
				system("cls");
				// Print both arrays in a clean list
				cout << "List 1:" << endl;
				PrintArray(namelist1, size1);
				cout << endl << "List 2:" << endl;
				PrintArray(namelist2, size2);
			} break;
			
			case 4: {
				system("cls");
				// if the first list is ordered, print a confirmation
				if (CheckValues(namelist1, size1))
					cout << "The values in list 1 are in order." << endl;
				// otherwise print an error
				else
					cout << "The values in list 1 are NOT in order." << endl;
				// same goes for the second list
				if (CheckValues(namelist2, size2))
					cout << "The values in list 2 are in order." << endl;
				else
					cout << "The values in list 2 are NOT in order." << endl;
			} break;
			
			case 5: {
				system("cls"); 
				// Calls Merge to combine the lists into one file
				Merge(namelist1, namelist2, size1, size2);
			} break;
			
			case 6: {
				system("cls");
				PrintFileContents(); 
			} break;
			
			default: {
				system("cls");
				cout << "Invalid option. Please try again." << endl;
			}
		}
		option = GetChoice();
	}

	return 0;
}

/*****************************************************************
FUNCTION:			GetChoice
PURPOSE:			Lets the user choose an option from a menu
INCOMING:			N/A
OUTGOING:			N/A
RETURN:				The user's choice as an integer
******************************************************************/
int GetChoice() {
	int choice=-1;
	
	// print a short menu of options
	cout << "----------------------------------------------" << endl;
	cout << "1. Input strings into Array #1 from a file" << endl;
	cout << "2. Input strings into Array #2 from a file" << endl;
	cout << "3. Print an array" << endl;
	cout << "4. Check if a file's contents are in order" << endl;
	cout << "5. Merge lists into one file" << endl;
	cout << "6. Print the contents of a file" << endl;
	cout << "0. Quit" << endl;
	cout << "----------------------------------------------" << endl << endl;
	// prompt & input
	cout << "Enter an option: ";
	cin >> choice;

	return choice;
}

/*****************************************************************
FUNCTION:			ReadFile
PURPOSE:			Sets a file's contents into an array and returns
					a value for the number of items in the file
INCOMING:			The array's address
OUTGOING:			The items of the file being read
RETURN:				The number of items in the file (max 10)
******************************************************************/
int ReadFile(string namelist[]) {
	int nItems=0;
	string filename;
	
	// prompt the user for a filename
	cout << "Enter a name of the file you want to open: ";
	cin >> filename;
	
	// make the variable iFile, which will load the user's requested filename
	ifstream iFile(filename.c_str());
	
	// if the file does not exist, print an error and return the values
	if (iFile.fail()) {
		cout << "ERROR: Unable to find file." << endl;
		return nItems;
	}
	
	// the program will read each name and store it while a counter checks for the number of items
	for (int i=0; i<MAX && iFile>>namelist[i]; i++) {
		nItems++;
	}

	// close the file and return the number of items stored
	iFile.close();
	return nItems;
}

/*****************************************************************
FUNCTION:			PrintArray
PURPOSE:			Prints the two arrays recorded
INCOMING:			The address of the array, the size of the array
OUTGOING:			N/A
RETURN:				N/A
******************************************************************/
void PrintArray(string namelist[], int size) {
	for (int i=0; i<size; i++)
		cout << namelist[i] << endl;
}

/*****************************************************************
FUNCTION:			CheckValues
PURPOSE:			Checks to see if the values in the array are
					in alphabetical order.
INCOMING:			The address of the array, size of the array
OUTGOING:			N/A
RETURN:				Whether or not the values are in order (true or
					false)
******************************************************************/
bool CheckValues(string namelist[], int size) {
	bool isOrdered=true;
	
	// variable for last string
	string lastString = namelist[0];

	// until the end of the array list, compare to see if the list is ordered
	for (int i=1; i<size; i++) {
		// if it is ordered, continue to check
		if (namelist[i] > lastString)
			lastString = namelist[i];
		// otherwise return false
		else {
			isOrdered = false; 
			break;
		}
	}

	return isOrdered;
}

/*****************************************************************
FUNCTION:			Merge
PURPOSE:			Combines two lists of items into one file
INCOMING:			The two arrays to be combined, the sizes of the
					arrays (one for each array)
OUTGOING:			The names into MarlarCole.out
RETURN:				N/A
******************************************************************/
void Merge(string names1[], string names2[], int size1, int size2) {
	// opens (or creates) MarlarCole.out
	ofstream oFile("MarlarCole.out");

	// if the two lists are in order, continue
	if (CheckValues(names1,size1) && CheckValues(names2,size2)) {
		// write the items of both arrays into the file
		for (int i=0; i<MAX; i++)
			oFile << names1[i] << endl << names2[i] << endl;
		// print a confirmation prompt
		cout << "Files successfully merged into MarlarCole.out." << endl;
	}
	// otherwise print an error
	else {
		cout << "One of the files are not in order. Please correct this." << endl;
	}

	// close the file
	oFile.close();
}

/*****************************************************************
FUNCTION:			PrintFileContents
PURPOSE:			Reads the contents of a single file and prints
					whatever is in it
INCOMING:			N/A
OUTGOING:			N/A
RETURN:				N/A
******************************************************************/
void PrintFileContents() {
	string filename;
	cout << "Enter the name of the file you want to open: ";
	cin >> filename;

	// open the file
	ifstream iFile(filename.c_str());

	// if the file does not exist, print an error and exit
	if (iFile.fail()) {
		cout << "ERROR: Unable to find file." << endl;
		return;
	}

	// print the contents of the file
	while(!iFile.eof()) {
		string name;
		iFile >> name;
		cout << name << endl;
	}

	// close the file when done
	iFile.close();
}