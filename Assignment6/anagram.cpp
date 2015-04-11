#include "anagram.h"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************
 * FUNCTION:        anagram
 * PURPOSE:         Calls the overloaded constructor with the
                    default filename "words.txt"
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************/
anagram::anagram() {
    anagram("words.txt");
}

/*************************************************************
 * FUNCTION:        anagram(string)
 * PURPOSE:         Creates a dictionary of words for use to
                    find anagrams
 * INCOMING:        A string class filename
 * OUTGOING:        The values of the file into a linked list
 * RETURN:          N/A
**************************************************************/
anagram::anagram(string fname) {
    ifstream inFile (fname.c_str());
    
    if ( inFile.fail() ) {
        cout << "ERROR: File " << fname << " does not exist in this directory." << endl;
        system("PAUSE"); // remove on non-Windows machines
        exit(1);
    }

    string theWord;

    for ( int i = 0; !inFile.eof(); i++ ) {
        inFile >> theWord;

        string theSig = makeSig(theWord);

        slist * newSig = new slist;
        newSig->sig = theSig;
        newSig->words.insert(theWord);
        sigList.push_back(*newSig);

        // to show that input is still working, show a conformation for every 100 words
        if ( i % 100 == 0 )
            cout << i << " words copied..." << endl;

        listSize = i;
    }

    // completion check & sort confirm
    cout << "Copying complete. " << listSize << " words copied." << endl;
    cout << "Sorting list... ";
    sort(sigList.begin(), sigList.end());
    cout << "Complete." << endl << endl;

    inFile.close();
}

/*************************************************************
 * FUNCTION:        findAnagrams
 * PURPOSE:         Searches for anagrams w/ a binary search
 * INCOMING:        A string class keyword, the left side,
                    and the right side
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************/
void anagram::findAnagrams(string value, int left, int right) {
    string valSig = makeSig(value);

    if ( left == right ) {
        if ( sigList[left].sig == valSig )
            searchLeftRight(valSig, left);
    }
    else {
        // Dividing by 2 gives us the middle portion
        int middle = ( left + right ) / 2;

        if ( sigList[middle].sig == valSig ) {
            searchLeftRight(valSig, middle);
        }
        else {
            if ( valSig > sigList[middle].sig ) findAnagrams(value, middle+1, right);
            else findAnagrams(value, left, middle-1);
        }
    }
}

/*************************************************************
 * FUNCTION:        searchLeftRight
 * PURPOSE:         Finds & prints any anagrams by checking to
                    the left and right of the list
 * INCOMING:        The signature, the position as an int
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************/
void anagram::searchLeftRight(string signature, int position) {
    // check to the right first
    for ( int i = position; (signature == sigList[i].sig) && (i<listSize); i++ ) {
        //sigList[i].words.print(&cout);
        cout << sigList[i].words;
    }

    // check to the left
    for ( int i = position-1; (signature == sigList[i].sig) && (i>=0); i-- ) {
        //sigList[i].words.print(&cout);
        cout << sigList[i].words;
    }
}

/*************************************************************
 * FUNCTION:        makeSig
 * PURPOSE:         Makes a signature of a word
 * INCOMING:        A string value to change
 * OUTGOING:        N/A
 * RETURN:          The signature as a string
**************************************************************/
string anagram::makeSig(string value) {
    for ( unsigned int i = 0; i < value.length(); i++ ) {
        unsigned int min = i;
        for ( unsigned int j = i; j < value.length(); j++ )
            if ( value[min] > value[j] ) min = j;
        // replace the letters accordingly
        char temp = value[i];
        value[i] = value[min];
        value[min] = temp;
    }
    return value;
}

/*************************************************************
 * FUNCTION:        getListSize
 * PURPOSE:         Returns the number of items in the list
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          The list size
**************************************************************/
int anagram::getListSize() const {
    return listSize;   
}
