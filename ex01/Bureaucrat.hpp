#ifndef  BUREAUCRAT_HPP   
#define  BUREAUCRAT_HPP   

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& t);
        Bureaucrat& operator=(const Bureaucrat& t);
        std::string getName();
        int getGrade();
        void gradeInc();
        void gradeDec();
        void signForm(Form& t);
    private:
        const std::string _name;
        int               _grade;

    class GradeTooHighException : public std::exception
    {
        public:
            const char * what () const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
            const char * what () const throw(); 
    };
};

std::ostream& operator << (std::ostream &o, Bureaucrat &c);

#endif
