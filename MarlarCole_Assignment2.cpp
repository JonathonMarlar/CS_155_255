/**********************************************************
Cole Marlar
CS 255 Spring 2012
Assignment:		Assignment #2
Description:	Make an array type with dynamic memory
				and sort the values in the array
				in descending order via selection sort.
***********************************************************/
#include <iostream>
using namespace std;

struct intArray {
	int size;
	int *elems;
};

void initArray(intArray &arr, int size);
void cleanupArray(intArray &arr);
void selectionSort(intArray arr);
void swapElements(intArray arr, int left, int max);
void displayList(intArray arr);

int main() {
	intArray myList = {0,0};
	int numElements = 0;

	// prompt user for array size, get user input, perform appropriate data validation
	do {
		cout << "How big do you want the array to be? : ";
		cin >> numElements;
	} while (numElements <= 0); // make sure it's a valid positive integer

	initArray(myList, numElements);

	displayList(myList);
	selectionSort(myList);
	displayList(myList);

	cleanupArray(myList);

	cin.ignore();
	cout << "Press any key to continue..." << endl;
	cin.get();
	return 0;
}

/****************************************************************
FUNCTION:		initArray
PURPOSE:		Initializes the array for the size described
				by the user and assigns values to it
INCOMING:		Memory location of the array address of
				intArray type, size	
OUTGOING:		Values assigned to array and array size
RETURN:			N/A
*****************************************************************/
void initArray(intArray &arr, int size) {
	arr.elems = new int [size];
	arr.size = size;
	
	for (int i=0; i<size; i++)
		arr.elems[i] = i+1;
}

/****************************************************************
FUNCTION:		cleanupArray
PURPOSE:		Gives back any memory borrowed for the array
INCOMING:		Memory address of an array of intArray type
OUTGOING:		Null pointers & values
RETURN:			N/A
*****************************************************************/
void cleanupArray(intArray &arr) {
	delete [] arr.elems;
	arr.size = 0;
}

/****************************************************************
FUNCTION:		selectionSort
PURPOSE:		Sorts the data in array of intArray type in
				descending order
INCOMING:		Array address of intArray type
OUTGOING:		Values of the array of intArray type in
				descending order
RETURN:			N/A
*****************************************************************/
void selectionSort(intArray arr) {
	
	for (int x=0; x<arr.size; x++) {
		int max = x; // start at 0 and work up the list
		
		// [y] is looking for the maximum integer to replace [x] with
		for (int y=x; y<arr.size; y++) {
			if (arr.elems[max]<arr.elems[y])
				max = y;
		}
		
		swapElements(arr, x, max);
	}
}

/****************************************************************
FUNCTION:		swapElements
PURPOSE:		Switches the two elements of an array of
				intArray type
INCOMING:		Array address of intArray type, the two elements
				needed to be switched
OUTGOING:		The elements switched around
RETURN:			N/A
*****************************************************************/
void swapElements(intArray arr, int left, int max) {
	int temp = arr.elems[left];
	arr.elems[left] = arr.elems[max];
	arr.elems[max] = temp;
}

/****************************************************************
FUNCTION:		displayList
PURPOSE:		Prints an array on the screen
INCOMING:		Array address of intArray type
OUTGOING:		N/A
RETURN:			N/A
*****************************************************************/
void displayList(intArray arr) {
	cout << endl;
	for (int i=0; i<arr.size; i++)
		cout << arr.elems[i] << endl;
}