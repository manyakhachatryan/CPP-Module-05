#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5), _target("not defind")
{
    std::cout<<"Default constructor called - PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("President", 25, 5), _target(target)
{
    std::cout<<"Default constructor called - PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout<<"Destructor called - PresidentialPardonForm"<<std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& t) :  AForm(t)
{
    _target=t._target;
    std::cout<<"Copy constructor called - PresidentialPardonForm"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& t) 
{
    if (this != &t)
    {
        _target=t._target;
    }
    std::cout<<"Copy assignment operator called - PresidentialPardonForm"<<std::endl;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(getSign() == 0)
    {
        throw AForm::NoSigned();
    }

    if (executor.getGrade() >  getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout <<getTarget()<< " has been pardoned by Zaphod Beeblebrox"<<std::endl;;
}

std::ostream& operator << (std::ostream &o, PresidentialPardonForm &c)
{
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Form name     : "<<c.getNameForm()<<std::endl;
    std::cout<<"Sign          : "<<c.getSign()<<std::endl;
    std::cout<<"Sign Grade    : "<<c.getSignGrade()<<std::endl;
    std::cout<<"Execute Grade : "<<c.getExecuteGrade()<<std::endl;
    std::cout<<"Target        : "<<c.getTarget()<<std::endl;
    std::cout<<"---------------------------------------------";
    return o;
}