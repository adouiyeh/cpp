#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>



bool isoper(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void handle_oper(std::stack<int>& nums, char oper)
{

    int n = nums.top();
    nums.pop();
    switch(oper)
    {
        case '+':
            nums.top() += n;
            break;
        case '-':
            nums.top() -= n;
            break;
        case '*':
            nums.top() *= n;
            break;
        case '/':
            if (n == 0)
               throw std::runtime_error("Error: division by zero.");
            nums.top() /= n;
            break;
    }
}

void handle_rpn(std::string& rpn, std::stack<int>& nums)
{

    for(size_t i = 0; i < rpn.size(); i++)
    {
        if (std::isspace(rpn[i]))
            continue;
        else if (std::isdigit(rpn[i]))
            nums.push(rpn[i] - '0');
        else if (isoper(rpn[i]))
        {
            if (nums.size() < 2)
                throw std::runtime_error("Error: invalid RPN expression.");
            handle_oper(nums, rpn[i]);
        }
        else
            throw std::runtime_error("Error: invalid character in RPN expression.");
    }
}




