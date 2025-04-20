#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _count;
        void _add(void);
        void _prompt(const char *msg, Contact& contact, void (Contact::*setter)(std::string& str));
        void _display(void);
        void _search(void);

    public:
        void run(void);
        PhoneBook();
        ~PhoneBook();
};

#endif