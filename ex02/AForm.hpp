#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{   
    public:
        AForm();
        AForm(std::string name, int num1, int num2);
        AForm(const AForm& t);
        AForm& operator=(const AForm& t);
        ~AForm();
        const std::string getNameForm() const;
        bool getSign() const;
        int getSignGrade();
        int getExecuteGrade() const;
        void beSigned(Bureaucrat &t); 
        virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            const char * what () const throw() 
            {
                return "Exception:? ";
            }
    };

    class GradeTooLowException : public std::exception
    {
         public:
            const char * what () const throw() 
            {
                return "Exception: The form's Grade is higher than Bureaucrat's grade ";
            }
    };

    class NoSigned : public std::exception
    {
         public:
            const char * what () const throw() 
            {
                return "The form doesn't signed";
            }
    };
    private:
        const std::string   _nameForm;
        bool                _sign;
        const int           _signGrade;
        const int           _executeGrade;


};

std::ostream& operator << (std::ostream &o, AForm &c);

#endif