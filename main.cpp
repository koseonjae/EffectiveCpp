#include <iostream>
#include "NamedObject.h"
#include "HomeForSale.h"
#include "UncopyableHomeForSale.h"
#include "DerivedAWOV.h"
#include "DerivedNamedObject.h"
#include "Lock.h"

void testChapter13( void )
{
    shared_ptr<DerivedNamedObject<int>> namedObject = make_shared<DerivedNamedObject<int>>( "four", 4, 4 );
    shared_ptr<DerivedAWOV> derivedAWOV = make_shared<DerivedAWOV>();
}

int main()
{
//    // CHAPTER 5
//    NamedObject object1( "one", 1 ); // constructor
//    NamedObject object2( object1 ); // copy constructor
//    object2 = object1; // copy assignment operator
//
//    // CHAPTER 6
//
//    HomeForSale forSale1;
//    HomeForSale forSale2;
////    HomeForSale forSale3( forSale1 ); // delete 키워드로 복사 생성자를 막음
////    forSale1 = forSale2; // delete 키워드로 인해 복사 대입 연산자를 막음
//
//    UncopyableHomeForSale uncopyableHomeForSale1;
//    UncopyableHomeForSale uncopyableHomeForSale2;
////    UncopyableHomeForSale uncopyableHomeForSale3( uncopyableHomeForSale1 ); // Uncopyable 상속으로 복사 생성자를 막음
////    uncopyableHomeForSale1 = uncopyableHomeForSale2; // Uncopyable 상속으로 복사 대입 연산자를 막음
//
//    AWOV *awov = new DerivedAWOV();
//    delete awov;
//
//    DerivedNamedObject derivedNamedObject1( "three", 3, 3 );
//
//    DerivedNamedObject derivedNamedObject2( derivedNamedObject1 );

    // CHAPTER 13
//    testChapter13();

    // CHAPTER 14
    Lock lock( new pthread_mutex_t );
    pthread_mutex_t *ptr1 = lock.get(); // 명시적 자원 get
    pthread_mutex_t *ptr2 = lock; // 암시적 자원 get, mutex가 아니라 Lock type에 대입하려고 한것일수도 있음 => 즉 실수의 위험이 있음

    return 0;
}
