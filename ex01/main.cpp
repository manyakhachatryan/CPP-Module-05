#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
      Bureaucrat a("manykhac", 1);
      Form b;
      Form c("form1", 5, 5);
      Form d(c);
      b = c;
      std::cout<<a<<std::endl;
      std::cout<<b<<std::endl;
      std::cout<<c<<std::endl;
      std::cout<<d<<std::endl;
  
      b.beSigned(a);
      b.beSigned(a);
    }
    catch(const std::exception& e)
    {
      std::cerr <<e.what() << '\n';
    }
    return (0);
}