#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("not defind")
{
    std::cout<<"Default constructor called - ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout<<"Default constructor called - ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"Destructor called - ShrubberyCreationForm"<<std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& t) :  AForm(t)
{
    _target=t._target;
    std::cout<<"Copy constructor called - ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& t) 
{
    if (this != &t)
    {
        _target=t._target;
    }
    std::cout<<"Copy assignment operator called - ShrubberyCreationForm"<<std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(getSign() == 0)
    {
        throw AForm::NoSigned();
    }

    if (executor.getGrade() >  getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::ofstream MyFile(getTarget()+"_shrubbery");
    MyFile <<" \n"      
<<"        #########\n" 
<<"     '### |##|### |#####'\n"
<<"     ##|### |||####_####_#\n"
<<"   ###  ||###|# |# # ###\n"
<<" ##_|_#|_|## | #####_#_####\n"
<<"## #### # | #| #  #### #####\n"
<<" __#_--###`  |#,###---###-~\n"
<<"           | ##\n"
<<"            ###\n"
<<"           ### \n"
<<"       ejm  ### \n"
<<"      , -=-~# .-^- _ \n"
<<"           #\n"
<<"           ##\n"
<<"\n";

    MyFile.close();
}

std::ostream& operator << (std::ostream &o, ShrubberyCreationForm &c)
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