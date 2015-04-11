#pragma once

template <class T>
class itsaTemp {
    public:
        itsaTemp();
        ~itsaTemp();

        bool insertItem(T item);
        int getNumofItems() const;
        T * getPointer() const;
        void printList() const;

    private:
        T * list;
        int numItems;
        bool noMemory() const;
};
