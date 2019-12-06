#include <iostream>
#include "NamedObject.h"
#include "HomeForSale.h"
#include "UncopyableHomeForSale.h"
#include "DerivedAWOV.h"
#include "DerivedNamedObject.h"

int main()
{
    // CHAPTER 5
    NamedObject object1( "one", 1 ); // constructor
    NamedObject object2( object1 ); // copy constructor
    object2 = object1; // copy assignment operator

    // CHAPTER 6

    HomeForSale forSale1;
    HomeForSale forSale2;
//    HomeForSale forSale3( forSale1 ); // delete 키워드로 복사 생성자를 막음
//    forSale1 = forSale2; // delete 키워드로 인해 복사 대입 연산자를 막음

    UncopyableHomeForSale uncopyableHomeForSale1;
    UncopyableHomeForSale uncopyableHomeForSale2;
//    UncopyableHomeForSale uncopyableHomeForSale3( uncopyableHomeForSale1 ); // Uncopyable 상속으로 복사 생성자를 막음
//    uncopyableHomeForSale1 = uncopyableHomeForSale2; // Uncopyable 상속으로 복사 대입 연산자를 막음

    AWOV *awov = new DerivedAWOV();
    delete awov;

    DerivedNamedObject derivedNamedObject1( "three", 3, 3 );

    DerivedNamedObject derivedNamedObject2( derivedNamedObject1 );

    return 0;
}
