#include "PhoneBook.hpp"

std::string format_col(std::string col, size_t w)
{
    if (col.length() > w)
    {
        col.resize(w - 1);
        col.push_back('.');
    }
    while (col.length() < w)
        col.push_back(' ');
    col.append(" | ");
    return col;
}

std::string intToString(int num)
{
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

PhoneBook::PhoneBook() : _count(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::run()
{
    std::string cmd;

    while (1)
    {
        std::cout << "Enter a cmd (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            return;
        else if (cmd == "EXIT")
            return;
        else if (cmd == "ADD")
            _add();
        else if (cmd == "SEARCH")
            _search();
    }
}

void PhoneBook::_add()
{
    int i = _count % 8;
    _prompt("First Name: ", _contacts[i], &Contact::setFirstName);
    _prompt("Last Name: ", _contacts[i], &Contact::setLastName);
    _prompt("Nick Name: ", _contacts[i], &Contact::setNickName);
    _prompt("Phone Number: ", _contacts[i], &Contact::setPhoneNumber);
    _prompt("Darkest Secret: ", _contacts[i], &Contact::setDarkestSecret);
    _count++;
}

void PhoneBook::_prompt(const char *msg, Contact &contact, void (Contact::*setter)(std::string &str))
{
    std::string str = "";

    while (str.empty())
    {
        std::cout << msg;
        if (!std::getline(std::cin, str))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            exit(1);
        }
    }
    (contact.*setter)(str);
}

void PhoneBook::_search()
{
    int i = 0;

    _display();
    std::cout << "Index (1-8): ";
    if ((std::cin >> i).fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Input\n";
    }
    else if (i >= 1 && i < _count + 1)
    {
        --i;
        std::cout << "First Name: " << _contacts[i].getFirstName() << "\n";
        std::cout << "Last Name: " << _contacts[i].getLastName() << "\n";
        std::cout << "Nick Name: " << _contacts[i].getNickName() << "\n";
        std::cout << "Phone Number: " << _contacts[i].getPhoneNumber() << "\n";
        std::cout << "Darkest Secret: " << _contacts[i].getDarkestSecret() << "\n";
    }
    else
        std::cout << "Invalid Index.\n";
    std::cin.ignore(10000, '\n');
}

void PhoneBook::_display()
{
    std::cout << "| " + format_col("Index:", 10);
    std::cout << format_col("First Name:", 10);
    std::cout << format_col("Last Name:", 10);
    std::cout << format_col("Nick Name:", 10);
    std::cout << format_col("Phone Number:", 10);
    std::cout << format_col("Darkest Secret:", 10);
    std::cout << "\n";
    for (int i = 0; i < _count && i < 8; i++)
    {
        std::cout << "| " << format_col(intToString(i + 1), 10);
        std::cout << format_col(_contacts[i].getFirstName(), 10);
        std::cout << format_col(_contacts[i].getLastName(), 10);
        std::cout << format_col(_contacts[i].getNickName(), 10);
        std::cout << format_col(_contacts[i].getPhoneNumber(), 10);
        std::cout << format_col(_contacts[i].getDarkestSecret(), 10);
        std::cout << "\n";
    }
}