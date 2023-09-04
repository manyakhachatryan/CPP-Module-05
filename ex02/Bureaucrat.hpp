#ifndef  BUREAUCRAT_HPP   
#define  BUREAUCRAT_HPP   

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& t);
        Bureaucrat& operator=(const Bureaucrat& t);
        std::string getName();
        int getGrade() const;
        void gradeInc();
        void gradeDec();
        void signForm(AForm& t);
        void executeForm(AForm const & form);
    private:
        const std::string _name;
        int               _grade;

    class GradeTooHighException : public std::exception
    {
        public:
            const char * what () const throw() 
            {
                return "Exception: The higher score is 1";
            }
    };

    class GradeTooLowException : public std::exception{
        public:
            const char * what () const throw() 
            {
                return "Exception: The lower score is 150";
            }
    };
};

std::ostream& operator << (std::ostream &o, Bureaucrat &c);

#endif
