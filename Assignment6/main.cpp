/*************************************************************
 * Cole Marlar
 * Project #6
 * CS 255
 * Description: Finds all anagrams (if any) from an external
                text file
**************************************************************/

#include "anagram.h"
#include <iostream>
using namespace std;

int main () {
    string fname;
    string word;

    cout << "Enter the filename to search (default -- words.txt): ";
    cin >> fname;

    anagram anagList(fname);
    
    cout << "Enter the word you wish to search by: ";
    cin >> word;
    
    anagList.findAnagrams(word, 0, anagList.getListSize());

    system("PAUSE"); // replace if on a non-Windows machine
    return 0;
}
