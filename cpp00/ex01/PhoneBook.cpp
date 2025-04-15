#include "PhoneBook.hpp"


void PhoneBook::run()
{
    std::string cmd;
    
    while (1)
    {
        std::cout << "Enter a cmd (ADD, SEARCH, EXIT): ";
        std::cin >> cmd;

        if (cmd == "EXIT")
            exit(0);
        else if (cmd == "ADD")
            _add();
        else if (cmd == "SEARCH")
            _search();
    }
}

// void PhoneBook::_add()
// {
//     _prompt("First Name: ", _contacts[_count], &Contact::setFirstName);
//     _prompt("Last Name: ", _contacts[_count], &Contact::setFirstName);
//     _prompt("Nick Name: ", _contacts[_count], &Contact::setFirstName);
//     _prompt("Name: ", _contacts[_count], &Contact::setFirstName);
// }

// void PhoneBook::_prompt(const char* msg, Contact& contact, void (Contact::*setter)(std::string& str))
// {
//     std::string str;

//     std::cout << msg;
//     std::cin >> str;
//     (contact.*setter)(str);
// }

void PhoneBook::_search()
{
    _display();
    std::cout << "searching...";
}

void PhoneBook::_display()
{
    std::cout << "...";
}