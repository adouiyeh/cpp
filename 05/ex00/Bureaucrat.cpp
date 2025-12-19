#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    checkGrade();
    std::cout << "Bureaucrat Constructor Called" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::checkGrade() const
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}