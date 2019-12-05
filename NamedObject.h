#pragma once

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

template<typename T>
class NamedObject
{
public:
    NamedObject( const string &name, const T &value )
    {
        printf( "NamedObject::Constructor %s \n", name.c_str() );
        this->name = name;
        this->value = value;
    }

    virtual ~NamedObject()
    {
        printf( "NamedObject::Destructor %s \n", name.c_str() );
    }

    NamedObject( const NamedObject &rhs )
    {
        printf( "NamedObject::CopysContructor %s \n", name.c_str() );
        this->name = rhs.name;
        this->value = rhs.value;
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
