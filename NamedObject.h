#pragma once

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

template<typename T>
class NamedObject
{
public:
    NamedObject( const string &name, const T &value ) : name( name ), value( value )
    {
        printf( "NamedObject::Constructor %s \n", name.c_str() );
    }

    virtual ~NamedObject()
    {
        printf( "NamedObject::Destructor %s \n", name.c_str() );
    }

    NamedObject( const NamedObject &rhs ) : name( rhs.name ), value( rhs.value )
    {
        printf( "NamedObject::CopysContructor %s \n", name.c_str() );
    }

    NamedObject &operator=( const NamedObject &rhs )
    {
        printf( "NamedObject::CopyAssignmentConstructor %s \n", name.c_str() );
        this->name = rhs.name;
        this->value = rhs.value;
        return *this;
    }

private:
    string name;
    T value;
};
