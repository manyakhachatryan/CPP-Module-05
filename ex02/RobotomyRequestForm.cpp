#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("not defind")
{
    std::cout<<"Default constructor called - RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
    std::cout<<"Default constructor called - RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout<<"Destructor called - RobotomyRequestForm"<<std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& t) :  AForm(t)
{
    _target=t._target;
    std::cout<<"Copy constructor called - RobotomyRequestForm"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& t) 
{
    if (this != &t)
    {
        _target=t._target;
    }
    std::cout<<"Copy assignment operator called - RobotomyRequestForm"<<std::endl;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(getSign() == 0)
    {
        throw AForm::NoSigned();
    }

    if (executor.getGrade() >  getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::srand(std::time(nullptr));
    int random_variable = std::rand();
    if(random_variable % 2 == 0)
		std::cout <<getNameForm() << " robotomized " << std::endl;
	else
		std::cout <<getNameForm() << " could not robotomize " << std::endl;

}

std::ostream& operator << (std::ostream &o, RobotomyRequestForm &c)
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