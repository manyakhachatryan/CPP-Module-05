#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{   
    public:
        Form();
        Form(std::string name, int num1, int num2);
        Form(const Form& t);
        Form& operator=(const Form& t);
        ~Form();
        const std::string getNameForm();
        bool getSign();
        int getSignGrade();
        int getExecuteGrade();
        void beSigned(Bureaucrat &t); 
    private:
        const std::string   _nameForm;
        bool                _sign;
        const int           _signGrade;
        const int           _executeGrade;


    class GradeTooHighException : public std::exception
    {
        public:
            const char * what () const throw();
    };

    class GradeTooLowException : public std::exception
    {
         public:
            const char * what () const throw();
    };
};

std::ostream& operator << (std::ostream &o, Form &c);

#endif