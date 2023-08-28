#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("many", 20);
   
    // std::cout<<a.getName()<<std::endl;
    // std::cout<<a.getGrade()<<std::endl;
    a.gradeInc();
    std::cout<<a<<std::endl;
 
    return (0);
}