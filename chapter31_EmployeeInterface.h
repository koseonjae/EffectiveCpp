#pragma once

#include <memory>
#include <string> // stl은 헤더 선언해도 병목 x

class EmployeeInterface
{
public:
    // Every interface class should have a virtual destructor. Virtual destructor makes sure that when a shape is deleted polymorphically,
    // correct destructor of the derived class is invoked. Otherwise there is a good chance of resource leak.
    virtual ~EmployeeInterface()
    {
    }

    virtual std::string name( void ) const = 0;
};

class EmployeeFactory
{
public:
    static std::shared_ptr<EmployeeInterface> create( const std::string& name );
};