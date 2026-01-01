#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {  
public:
    MutantStack() {};
    MutantStack(const MutantStack& other) : std::stack<T>(other) {};
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    };
    ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin(void) {
		return std::stack<T>::c.begin();
	};
	iterator end(void) {
		return std::stack<T>::c.end();
	};

	const_iterator begin(void) const {
		return std::stack<T>::c.begin();
	};
	const_iterator end(void) const {
		return std::stack<T>::c.end();
	};

};

