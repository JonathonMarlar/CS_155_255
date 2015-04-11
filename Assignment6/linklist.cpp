#include "linklist.h"
#include <new>
using namespace std;

/*************************************************************
 * FUNCTION:        linklist
 * PURPOSE:         Initializes a linked list class
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************/
linklist::linklist() : head(0) {}

/*************************************************************
 * FUNCTION:        ~linklist
 * PURPOSE:         Returns memory used for linked lists
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          N/A
**************************************************************/
linklist::~linklist() {
    // for some reason, this destuctor leads to a seg fault on Linux.
    // If necessary, comment this function out and it should work OK.
    wlist * temp;

    // go through each one to delete
    while (temp != 0) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

/*************************************************************
 * FUNCTION:        insert
 * PURPOSE:         Puts a string value into a linked list
 * INCOMING:        String value
 * OUTGOING:        Value stored into a linked list
 * RETURN:          TRUE if the insertion was successful
**************************************************************/
bool linklist::insert(string value) {
    if ( noMemory() ) return false;
    else {
        wlist * newword = new wlist;
        newword->word = value;
        newword->next = head;
        head = newword;
    }
    return true;
}

/*************************************************************
 * FUNCTION:        print
 * PURPOSE:         Prints off a linked list
 * INCOMING:        ostream pointer
 * OUTGOING:        The word into an ostream variable
 * RETURN:          N/A
**************************************************************/
void linklist::print(ostream * os) const {
    wlist * temp = head;

    while ( temp != 0 ) {
        *os << temp->word << endl;
        temp = temp->next;
    }
}

/*************************************************************
 * FUNCTION:        <<
 * PURPOSE:         Calls linklist::print for a linked list
 * INCOMING:        ostream variable and a linked list
 * OUTGOING:        N/A
 * RETURN:          The output stream
**************************************************************/
ostream & operator << (std::ostream & os, linklist & source) {
    source.print(&os);
    return os;
}

/*************************************************************
 * FUNCTION:        noMemory
 * PURPOSE:         Tests to see if there is enough memory to
                    insert a word into a linked list
 * INCOMING:        N/A
 * OUTGOING:        N/A
 * RETURN:          TRUE if there is no memory available
**************************************************************/
bool linklist::noMemory() const {
    wlist * temp;

    try {
        temp = new wlist;
        delete temp;
        return false;
    }

    catch(bad_alloc e) {
        return true;
    }
}
