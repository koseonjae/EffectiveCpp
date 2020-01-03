#include <memory>
#include <iostream>
#include "chapter31_Employee.h"

int main( void )
{
    std::shared_ptr<EmployeeInterface> a = EmployeeFactory::create( "name1" );
    auto b = a;
    auto c = a;

    a.reset( new Employee( "name2" ) );

    if( a != nullptr )
    {
        std::cout << a->name() << std::endl;
    }
    else
    {
        std::cout << "empty" << std::endl;
    }
    return 0;
}
