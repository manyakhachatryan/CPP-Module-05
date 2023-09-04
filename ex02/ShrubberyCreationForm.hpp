#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& t);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& t);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

std::ostream& operator << (std::ostream &o, ShrubberyCreationForm &c);

#endif
