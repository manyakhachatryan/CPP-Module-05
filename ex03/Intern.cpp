#include "Intern.hpp"

Intern::Intern() 
{
    std::cout<<"Default constructor called - Intern"<<std::endl;
}

Intern::~Intern()
{
    std::cout<<"Destructor called - Intern"<<std::endl;
}

Intern::Intern(const Intern& t)
{
    (void)t;
    std::cout<<"Copy constructor called - Intern"<<std::endl;
}

Intern& Intern::operator=(const Intern& t)
{
    (void)t;
    std::cout<<"Copy assignment operator called - Intern "<<std::endl;
    return *this;
}


AForm* Intern::makeForm(std::string str1, std::string str2)
{
    std::string types[3] = {"Shrubbery", "Robotomy", "President"};
    for(int i = 0; i < 3; i++)
    {
        if(str1 == types[i])
        {
            switch(i) {
            case 0:
                return new ShrubberyCreationForm(str2);
                break;
            case 1:
                return new RobotomyRequestForm(str2);
                break;
            case 2:
                return new PresidentialPardonForm(str2);
                break;
            }
        }
    }
    throw AForm::UnknownTypeException();
    return 0;
}