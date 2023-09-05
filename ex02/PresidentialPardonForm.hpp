#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& t);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& t);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

std::ostream& operator << (std::ostream &o, PresidentialPardonForm &c);

#endif