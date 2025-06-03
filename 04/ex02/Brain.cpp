#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "";
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = copy._ideas[i];
	std::cout << "Brain Copy Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain Copy Assignation called" << std::endl;
	return *this;
}

const std::string Brain::getIdea(size_t i) const
{
	if (i < 100)
		return _ideas[i];
	std::cerr << "Invalid index" << std::endl;
	return "";
}

void Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		_ideas[i] = idea;
	else
		std::cerr << "Invalid index" << std::endl;
}
