#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
      Bureaucrat a("manykhac", 2);

      Intern someRandomIntern;
      AForm* rrf;
      rrf = someRandomIntern.makeForm("Robotomy", "Bender");
      rrf->beSigned(a);
      rrf->execute(a);
    }
    catch(const std::exception& e)
    {
      std::cerr <<e.what() << '\n';
    }
    return (0);
}


  
