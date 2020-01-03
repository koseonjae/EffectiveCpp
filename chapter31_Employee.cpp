//
// Created by USER on 2019-12-27.
//

#include "chapter31_Employee.h"

Employee::Employee( const std::string& name ) : m_name( name )
{

}

Employee::~Employee()
{

}

std::string Employee::name( void ) const
{
    return m_name;
}

std::shared_ptr<EmployeeInterface> EmployeeFactory::create( const std::string& name )
{
    return std::shared_ptr<EmployeeInterface>( new Employee( name ) );
}
