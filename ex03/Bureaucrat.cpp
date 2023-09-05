#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
    std::cout<<"Default constructor called - Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
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

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::gradeInc()
{
    if(_grade == 1)
    {
        throw GradeTooHighException();
    }
    --_grade;
}

void Bureaucrat::gradeDec()
{
   if(_grade == 150)
    {
        throw GradeTooLowException();
    }
    ++_grade;
}

void Bureaucrat::signForm(AForm &t)
{
    try
    {
		std::cout << _name << " signed " << t.getNameForm() << std::endl;
	} catch (const std::exception& e)
    {
		std::cout   << _name << " couldn't sign " << t.getNameForm()
                    << " because " << e.what() << std::endl;
	}
}


void Bureaucrat::executeForm(AForm const & form)
{
   try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getNameForm() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

std::ostream & operator << (std::ostream &o,Bureaucrat &c)
{
    std::cout<<c.getName()<<", bureaucrat grade "<<c.getGrade()<<".";
    return o;
}


const char * Bureaucrat::GradeTooHighException::what () const throw()
{
    return "Exception: The higher score is 1";
}

const char * Bureaucrat::GradeTooLowException::what () const throw()
{
    return "Exception: The lower score is 150";
}