#pragma once

#include "NamedObject.h"

template < typename T >
class DerivedNamedObject : public NamedObject< T >
{
public:
    DerivedNamedObject( const string& name, const T& value, const T& value2 )
            : NamedObject< T >( name, value ), value2( value2 )
    {
        printf( "DerivedNamedObject::Constructor \n" );
    }

    virtual ~DerivedNamedObject()
    {
        printf( "DerivedNamedObject::Destructor \n" );
    }

    DerivedNamedObject( const DerivedNamedObject& rhs )
            : NamedObject< T >::NamedObject( rhs ), value2( rhs.value2 )
    {
        printf( "DerivedNamedObject::CopysContructor \n" );
    }

    DerivedNamedObject& operator=( const DerivedNamedObject& rhs )
    {
        printf( "DerivedNamedObject::CopyAssignmentConstructor \n" );
        NamedObject< T >::operator=( rhs );
        value2 = rhs.value2;
        return *this;
    }

private:
    T value2;
};
