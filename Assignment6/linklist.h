#pragma once

#include <ostream>
#include <string>

struct wlist {
    std::string word;
    wlist * next;
};

class linklist {
    public:
        linklist();
        ~linklist();

        bool insert(std::string value);
        void print(std::ostream * os) const;

    private:
        wlist * head;
        bool noMemory() const;
};

std::ostream & operator << (std::ostream & os, linklist & source);
