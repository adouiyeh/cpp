#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact _contacts[8];
        size_t _count = 0;
        void _add(void);
        void _prompt(const char *msg, Contact& contact, void (Contact::*setter)(std::string& str));
        void _display(void);
        void _search(void);

    public:
        void run(void);
};

#endif