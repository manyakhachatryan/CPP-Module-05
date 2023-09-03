#include "Form.hpp"

Form::Form(): _nameForm("unknown"), _signGrade(0), _executeGrade(0)
{
    _sign = false;
    std::cout<<"Default constructor called - Form"<<std::endl;
}

Form::Form(std::string name, int num1, int num2): _nameForm(name), _signGrade(num1), _executeGrade(num2)
{
    std::cout<<"Parameterized constructor called - Form"<<std::endl;
}

Form::~Form()
{
    std::cout<<"Destructor called - Form"<<std::endl;
}


Form::Form(const Form& t) : _nameForm(t._nameForm), _signGrade(t._signGrade), _executeGrade(t._executeGrade)
{
    _sign = t._sign;
    std::cout<<"Copy constructor called - Form"<<std::endl;
}

Form& Form::operator=(const Form& t)
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

const std::string Form::getNameForm()
{
    return _nameForm;
}

bool Form::getSign()
{
    return _sign;
}

int Form::getSignGrade()
{
    return _signGrade;
}

int Form::getExecuteGrade()
{
    return _executeGrade;
}


void Form::beSigned(Bureaucrat &t)
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

std::ostream& operator << (std::ostream &o, Form &c)
{
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"Form name     : "<<c.getNameForm()<<std::endl;
    std::cout<<"Sign          : "<<c.getSign()<<std::endl;
    std::cout<<"Sign Grade    : "<<c.getSignGrade()<<std::endl;
    std::cout<<"Execute Grade : "<<c.getExecuteGrade()<<std::endl;
    std::cout<<"---------------------------------------------";
    return o;
}