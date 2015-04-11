/****************************************************
Cole Marlar
Project 5
This program deals with manipulating matrices and
forming a matrix from a file.
2 December 2011
*****************************************************/
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
using namespace std;

const int MAX = 10;

// this lets the user pick the options from a menu
int GetChoice();
/// lets the user pick a matrix to use for functions
int GetMatrixChoice();
// enters values from a file and stores them into a matrix
void InputMatrix(string filename, int ar[][MAX], int& rowSize, int& colSize);
// prints a matrix starting with rows
void PrintRowMajor(int ar[][MAX], int rowSize, int colSize);
// prints a matrix starting with columns
void PrintColMajor(int ar[][MAX], int rowSize, int colSize);
// multiplies all the values in the row
int MultiplyRow(int ar[][MAX], int rowSize, int colSize);
// prints the minimum value of each column
void PrintMinCol(int ar[][MAX], int rowSize, int colSize);
// adds together two matrices
void AddMatrices(int ar1[][MAX], int ar2[][MAX], int rowSize, int colSize);

int main() {
	int matrix1[MAX][MAX]={0}, matrix2[MAX][MAX]={0};
	int rowSize1=0, rowSize2=0;
	int colSize1=0, colSize2=0;

	int choice = GetChoice();

	// until the user enters 0 to exit, do an action based on the user's choice
	while (choice!=0) {
		switch(choice) {
			// CASE 1: INPUT MATRIX
			case 1: {
				system("cls");
				string filename;
				cout << "Enter the filename for the first matrix: ";
				cin >> filename;
				InputMatrix(filename, matrix1, rowSize1, colSize1);
				cout << "Enter the filename for the second matrix: ";
				cin >> filename;
				InputMatrix(filename, matrix2, rowSize2, colSize2);
			} break;

			// CASE 2: PRINT A MATRIX, ROW MAJOR
			case 2: {
				system("cls");
				// the variable to hold the choice for what matrix to use
				int matChoice = GetMatrixChoice();
				// if the choice is 1, print the first matrix, otherwise print the second one
				if (matChoice==1)
					PrintRowMajor(matrix1, rowSize1, colSize1);
				else
					PrintRowMajor(matrix2, rowSize2, colSize2);
			} break;

			// CASE 3: PRINT A MATRIX, COLUMN MAJOR
			case 3: {
				system("cls");
				// the variable to hold the choice for what matrix to use
				int matChoice = GetMatrixChoice();
				// if the choice is 1, print the first matrix, otherwise print the second one
				if (matChoice==1)
					PrintColMajor(matrix1, rowSize1, colSize1);
				else
					PrintColMajor(matrix2, rowSize2, colSize2);
			} break;

			// CASE 4: MULTIPLY THE VALUES OF A ROW
			case 4: {
				system("cls");
				// get the user's choice of matrix and pass the correct values accordingly
				int matChoice = GetMatrixChoice();
				// the value to store the product
				int product = 0;
				if (matChoice==1)
					product = MultiplyRow(matrix1, rowSize1, colSize1);
				else
					product = MultiplyRow(matrix2, rowSize2, colSize2);
				// print the product
				cout << "The product of the row is " << product << "." << endl;
			} break;

			// CASE 5: PRINT THE MINIMUM VALUE OF EACH COLUMN
			case 5: {
				system("cls");
				// get the user's choice of matrix
				int matChoice = GetMatrixChoice();
				// apply the correct values accordingly
				if (matChoice==1)
					PrintMinCol(matrix1, rowSize1, colSize1);
				else
					PrintMinCol(matrix2, rowSize2, colSize2);
			} break;

			// CASE 6: ADD TWO MATRICES TOGETHER
			case 6: {
				system("cls");
				// if the matrices are the same size, add them together
				if (rowSize1==rowSize2 && colSize1==colSize2)
					AddMatrices(matrix1, matrix2, rowSize1, colSize1);
				// otherwise print an error
				else
					cout << "The matrices are not the same size. Please correct this and try again." << endl;
			} break;

			// DEFAULT: PRINT AN ERROR
			default: {
				system("cls");
				cout << "Invalid option. Please try again." << endl;
			}
		}
		// get the user's choice if he/she wants to continue
		choice = GetChoice();
	}

	return 0;
}

/*************************************************************************
FUNCTION:		GetChoice
PURPOSE:		Prints a menu of choices that allows
				the user to pick
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The user's choice
**************************************************************************/
int GetChoice() {
	int choice=0;

	cout << "*******************************************************" << endl;
	cout << "                       MATRICES                        " << endl;
	cout << "*******************************************************" << endl;
	cout << "1. Store a matrix from a file" << endl;
	cout << "2. Print a matrix (row major)" << endl;
	cout << "3. Print a matrix (column major)" << endl;
	cout << "4. Multiply values in a row" << endl;
	cout << "5. Print the min. value in each column in a matrix" << endl;
	cout << "6. Add two matrices together" << endl;
	cout << "0. Exit the program" << endl;
	cout << "*******************************************************" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

/*************************************************************************
FUNCTION:		GetMatrixChoice
PURPOSE:		Allows the user to choose which matrix to use in a
				function
INCOMING:		N/A
OUTGOING:		N/A
RETURN:			The user's choice of matrix
**************************************************************************/
int GetMatrixChoice() {
	int choice=0;

	// loop until a valid answer is made
	while (choice!=1 || choice!=2) {
		// Prompt for the choice
		cout << "Which matrix do you want to use, 1 or 2?" << endl;
		cin >> choice;
		// if it's not valid, print an error to show it is invalid
		if (choice!=1 && choice!=2) {
			system("cls");
			cout << "Invalid. Please enter the correct format." << endl;
		}
		else break;
	}

	return choice;
}

/*************************************************************************
FUNCTION:		InputMatrix
PURPOSE:		Reads a filename and assigns values to a matrix based
				on the information in the external file
INCOMING:		Filename, the array address
OUTGOING:		The row and column sizes
RETURN:			N/A
**************************************************************************/
void InputMatrix(string filename, int ar[][MAX], int& rowSize, int& colSize) {
	// open the file
	ifstream inFile(filename.c_str());
	
	// if the file doesn't exist, show an error and quit
	if (inFile.fail()) {
		cout << "The file cannot be found." << endl;
		return;
	}

	// input the number of rows & columns to use
	inFile >> rowSize >> colSize;

	// then set the values of the matrix based on the size
	for (int r=0; r<rowSize; r++)
		for (int c=0; c<colSize; c++)
			inFile >> ar[r][c];

	// print a confirmation
	cout << "Matrix successfully saved." << endl << endl;

	// Close the file
	inFile.close();
}

/*************************************************************************
FUNCTION:		PrintRowMajor
PURPOSE:		Prints a matrix by row numbers first
INCOMING:		Array address, the row and column size of the array
OUTGOING:		N/A
RETURN:			N/A
**************************************************************************/
void PrintRowMajor(int ar[][MAX], int rowSize, int colSize) {
	for (int r=0; r<rowSize; r++) {
		for (int c=0; c<colSize; c++)
			cout << ar[r][c] << "\t";
		cout << endl;
	}
}

/*************************************************************************
FUNCTION:		PrintColMajor
PURPOSE:		Prints a matrix by column numbers first
INCOMING:		Array address, the row and column size of the array
OUTGOING:		N/A
RETURN:			N/A
**************************************************************************/
void PrintColMajor(int ar[][MAX], int rowSize, int colSize) {
	for (int c=0; c<colSize; c++) {
		for (int r=0; r<rowSize; r++)
			cout << ar[r][c] << "\t";
		cout << endl;
	}
}

/*************************************************************************
FUNCTION:		MultiplyRow
PURPOSE:		Multiplies all the values in a row given by the user
INCOMING:		Array address, the row and column size of the array
OUTGOING:		N/A
RETURN:			The product
**************************************************************************/
int MultiplyRow(int ar[][MAX], int rowSize, int colSize) {
	int rowNum; // the row number the user wishes to multiply the values
	cout << "Enter the row number you wish to multiply: ";
	cin >> rowNum;

	// if the row number isn't valid, print an error and return
	if (rowNum>=rowSize) {
		cout << "This row is invalid. Please try again." << endl;
		return 0;
	}

	// start the product at the beginning
	int product = ar[rowNum][0];
	// loop through and multiply through each one
	for (int i=1; i<colSize; i++)
		product*=ar[rowNum][i];

	return product;
}

/*************************************************************************
FUNCTION:		PrintMinCol
PURPOSE:		Prints the smallest value of each column in a matrix
INCOMING:		Array address, the row and column size of the array
OUTGOING:		N/A
RETURN:			N/A
**************************************************************************/
void PrintMinCol(int ar[][MAX], int rowSize, int colSize) {
	// For each column, find the minimum
	for (int c=0; c<colSize; c++) {
		int min=INT_MAX;
		// Goes through each row to see if there's a minimum value
		for (int r=0; r<rowSize; r++) {
			// if there's a smaller number, assign it to minimum
			if (min > ar[r][c])
				min = ar[r][c];
		}
		// print the minimum of the column
		cout << "The minimum of column " << c << " is " << min << endl;
	}
}

/*************************************************************************
FUNCTION:		AddMatrices
PURPOSE:		Adds together two matrices
INCOMING:		Array addresses of the first and second matrix, 
				the row and column size of the array
OUTGOING:		N/A
RETURN:			N/A
**************************************************************************/
void AddMatrices(int ar1[][MAX], int ar2[][MAX], int rowSize, int colSize) {
	int addArray[MAX][MAX];

	for (int r=0; r<rowSize; r++)
		for (int c=0; c<colSize; c++)
			addArray[r][c] = ar1[r][c] + ar2[r][c];

	// print the result
	cout << "Matrix 1: " << endl;
	PrintRowMajor(ar1, rowSize, colSize);
	cout << endl << "Matrix 2: " << endl;
	PrintRowMajor(ar2, rowSize, colSize);
	cout << endl << "Added matrix:" << endl;
	PrintRowMajor(addArray, rowSize, colSize);
}