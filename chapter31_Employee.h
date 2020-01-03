#pragma once

#include "chapter31_EmployeeInterface.h"

class Employee : public EmployeeInterface
{
public:
    Employee( const std::string& name );

    ~Employee();

    std::string name( void ) const;
private:
    std::string m_name;
};
