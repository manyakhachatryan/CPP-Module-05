#ifndef ROBOTYREQUESTFORM_HPP
#define ROBOTYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& t);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& t);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;
};

std::ostream& operator << (std::ostream &o, RobotomyRequestForm &c);

#endif