#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Bureaucrat a("manykhac", 151);
      a.gradeInc();
      a.gradeDec();
      std::cout<<a<<std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr <<e.what() << '\n';
    }
    return (0);
}