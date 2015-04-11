/*************************************************************************
 * Jonathon Cole Marlar
 * CS 255
 * Assignment #7
 * Description: Lets the user insert items into a dynamic array via a
                template and call functions to display/manipulate the array
**************************************************************************/
#include "template.h"
#include <iostream>
#include <new>
using namespace std;

int main() {
    // itsaTemp class can be any type!
    itsaTemp<int> templateints;

    templateints.insertItem(11);
    templateints.insertItem(27);
    templateints.insertItem(7);

    int x = templateints.getNumofItems();
    cout << x << " number of items in the list" << endl << endl;

    cout << "Using the print function: " << endl;
    templateints.printList();

    // example of getting a pointer
    cout << endl << "Using getPointer: " << endl;
    int * mylist = templateints.getPointer();
    for ( int i = 0; i < templateints.getNumofItems(); i++ )
        cout << mylist[i] << endl;

    system("PAUSE"); // replace on non-Windows machines
    return 0;
}

/*************************************************************************
 * FUNCTION:        itsaTemp
 * PURPOSE:         Creates an instance of class itsaTemp
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************************/
template <class T>
itsaTemp<T>::itsaTemp() {
    numItems = 0;
    list = 0;
}

/*************************************************************************
 * FUNCTION:        ~itsaTemp
 * PURPOSE:         Returns allocated memory to the computer
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************************/
template <class T>
itsaTemp<T>::~itsaTemp() {
    delete [] list;
}

/*************************************************************************
 * FUNCTION:        insertItem
 * PURPOSE:         Adds an item to the list dynamically
 * INCOMING:        The item of class T (specified by the user)
 * OUTGOING:        The value stored in the list
 * RETURN:          TRUE if memory allocation was successful
**************************************************************************/
template <class T>
bool itsaTemp<T>::insertItem(T item) {
    if ( noMemory() ) return false;
    else {
        // make a new array with an extra size bigger than numItems
        T * temp = new T [numItems+1];
        copy(list, list+numItems, temp);
        temp[numItems] = item;
        delete [] list;
        list = temp;
        numItems++;
    }

    return true;
}

/*************************************************************************
 * FUNCTION:        getNumofItems
 * PURPOSE:         Returns the total number of items in the list
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          The number of items
**************************************************************************/
template <class T>
int itsaTemp<T>::getNumofItems() const {
    return numItems;
}

/*************************************************************************
 * FUNCTION:        getPointer
 * PURPOSE:         Returns a pointer to the list
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          The pointer to a dynamic array
**************************************************************************/
template <class T>
T * itsaTemp<T>::getPointer() const {
    return list;
}

/*************************************************************************
 * FUNCTION:        printList
 * PURPOSE:         Prints the list on the screen
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************************/
template <class T>
void itsaTemp<T>::printList() const {
    for (int i = 0; i < numItems; i++ )
        cout << list[i] << endl;
}

/*************************************************************************
 * FUNCTION:        noMemory
 * PURPOSE:         Tests to see if memory is available
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          TRUE if there is no more usable memory
**************************************************************************/
template <class T>
bool itsaTemp<T>::noMemory() const {
    T * test;
    try {
        test = new T;
        delete test;
        return false;
    }
    catch(bad_alloc e) {
        return true;
    }
}
