#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
      Bureaucrat a("manykhac", 12);
      ShrubberyCreationForm b("Home");
      b.beSigned(a);

      std::cout<<b<<std::endl;
      a.executeForm(b);
    }
    catch(const std::exception& e)
    {
      std::cerr <<e.what() << '\n';
    }
    return (0);
}


  
