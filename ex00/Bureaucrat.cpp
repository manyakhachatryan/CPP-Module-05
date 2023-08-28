#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown")
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name),  _grade(grade)
{
    
}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(const Bureaucrat& t)
{
    _name = t._name;
    // _grade = t._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& t)
{
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
    ++_grade;
}
void Bureaucrat::gradeDec()
{
    --_grade;
}

std::ostream & operator << (std::ostream &o,Bureaucrat &c)
{
    std::cout<<c.getName()<<", bureaucrat grade "<<c.getGrade()<<".";
    return o;
}