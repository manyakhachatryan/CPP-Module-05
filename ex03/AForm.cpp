#include "AForm.hpp"

AForm::AForm(): _nameForm("unknown"), _signGrade(0), _executeGrade(0)
{
    _sign = false;
    std::cout<<"Default constructor called - Form"<<std::endl;
}

AForm::AForm(std::string name, int num1, int num2): _nameForm(name), _signGrade(num1), _executeGrade(num2)
{
    _sign = false;
    std::cout<<"Parameterized constructor called - Form"<<std::endl;
}

AForm::~AForm()
{
    std::cout<<"Destructor called - Form"<<std::endl;
}


AForm::AForm(const AForm& t) : _nameForm(t._nameForm), _signGrade(t._signGrade), _executeGrade(t._executeGrade)
{
    _sign = t._sign;
    std::cout<<"Copy constructor called - Form"<<std::endl;
}

AForm& AForm::operator=(const AForm& t)
{
    if (this != &t)
    {
        _sign = t._sign;
        const_cast<std::string&>(_nameForm) = t._nameForm;
        const_cast<int&>(_signGrade) = t._signGrade;
        const_cast<int&>(_executeGrade) = t._executeGrade;
    }
    std::cout<<"Copy assignment operator called - Form"<<std::endl;
    return *this;
}

const std::string AForm::getNameForm()  const
{
    return _nameForm;
}

bool AForm::getSign() const
{
    return _sign;
}

int AForm::getSignGrade()
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}


void AForm::beSigned(Bureaucrat &t)
{
   
    if (t.getGrade() <= _signGrade)
    {
        if(_sign == 0)
        {
            _sign = true;
            t.signForm(*this);
        }
        else
        {
             std::cout<<getNameForm()<<"'s already signed"<<std::endl;
        }
    }
    else
        throw GradeTooLowException();      
}

std::ostream& operator << (std::ostream &o, AForm &c)
{
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Form name     : "<<c.getNameForm()<<std::endl;
    std::cout<<"Sign          : "<<c.getSign()<<std::endl;
    std::cout<<"Sign Grade    : "<<c.getSignGrade()<<std::endl;
    std::cout<<"Execute Grade : "<<c.getExecuteGrade()<<std::endl;
    std::cout<<"---------------------------------------------";
    return o;
}


const char * AForm::GradeTooHighException::what () const throw()
{
    return "Exception: The higher score is 1";
}

const char * AForm::GradeTooLowException::what () const throw()
{
    return "Exception: The form's Sign Grade is higher than Bureaucrat's grade ";
}

const char * AForm::NoSigned::what () const throw()
{
    return "The form doesn't signed";
}