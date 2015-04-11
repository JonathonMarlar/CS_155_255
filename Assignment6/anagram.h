#pragma once

#include "linklist.h"
#include <vector>

struct slist {
    std::string sig;
    linklist words;
    bool operator < (const slist& x) const { return ( sig < x.sig ); }
};

class anagram {
    public:
        anagram();
        anagram(std::string fname);

        void findAnagrams(std::string value, int left, int right);
        void searchLeftRight(std::string signature, int position);
        int getListSize() const;

    private:
        std::string makeSig(std::string value);
        std::vector<slist> sigList;
        int listSize;
};
