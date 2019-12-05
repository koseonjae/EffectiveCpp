#include <iostream>
#include "NamedObject.h"

int main()
{
    NamedObject object1( "one", 1 ); // constructor
    NamedObject object2( object1 ); // copy constructor
    object2 = object1; // copy assignment operator
    return 0;
}
