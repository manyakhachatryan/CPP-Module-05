#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
      Bureaucrat a("manykhac", 2);
      ShrubberyCreationForm b("Home");
      RobotomyRequestForm c("ZoZo");
      PresidentialPardonForm d("Pre");
      
      b.beSigned(a);
      c.beSigned(a);
      d.beSigned(a);

      std::cout<<b<<std::endl;
      std::cout<<c<<std::endl;
      std::cout<<d<<std::endl;

      a.executeForm(b);
      a.executeForm(c);
      a.executeForm(d);
    }
    catch(const std::exception& e)
    {
      std::cerr <<e.what() << '\n';
    }
    return (0);
}


  
