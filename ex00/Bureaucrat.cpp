#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
    std::cout<<"Default constructor called - Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
 
    if (grade < 0)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    else
        _grade = grade;
    std::cout<<"Parameterized constructor called - Bureaucrat"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Destructor called - Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& t) : _name(t._name), _grade(t._grade)
{
    std::cout<<"Copy constructor called - Bureaucrat"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& t)
{
    if (this != &t)
    {
        _grade = t._grade;
        const_cast<std::string&>(_name) = t._name;
    }
    std::cout<<"Copy assignment operator called - Bureaucrat "<<std::endl;
    return *this;
    
}

std::string Bureaucrat::getName() 
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::gradeInc()
{
    if(_grade == 150)
    {
        throw GradeTooHighException();
    }
    ++_grade;
}

void Bureaucrat::gradeDec()
{
    if(_grade == 0)
    {
        throw GradeTooHighException();
    }
    --_grade;
}

std::ostream & operator << (std::ostream &o,Bureaucrat &c)
{
    std::cout<<c.getName()<<", bureaucrat grade "<<c.getGrade()<<".";
    return o;
}