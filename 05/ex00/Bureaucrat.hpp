#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    void checkGrade() const;

public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    const std::string &getName() const;
    int getGrade() const;
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif