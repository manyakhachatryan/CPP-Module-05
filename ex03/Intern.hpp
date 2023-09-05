#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern(); 
        Intern(const Intern& t);
        Intern& operator=(const Intern& t);
        AForm*  makeForm(std::string str1, std::string str2); 
};

#endif