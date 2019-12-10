#include <iostream>
#include "NamedObject.h"
#include "HomeForSale.h"
#include "UncopyableHomeForSale.h"
#include "DerivedAWOV.h"
#include "DerivedNamedObject.h"
#include "Lock.h"
#include "Lock2.h"
#include "Investment.h"

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
//    Lock lock( new pthread_mutex_t );
//    pthread_mutex_t *ptr1 = lock.get(); // 명시적 자원 get
//    pthread_mutex_t *ptr2 = lock; // 암시적 자원 get, mutex가 아니라 Lock type에 대입하려고 한것일수도 있음 => 즉 실수의 위험이 있음

    pthread_mutex_t *mutexPts = new pthread_mutex_t;
    Lock2 lock2( mutexPts );

    // MAKE_SHARED
    // raw pointer 직접 건드리지 않아 안전 & allocater, deallocater 지정 불가 & 메모리할당이 한번에 이뤄지므로 메모리 릭의 위험 없음
    // new를 할 경우 f(shared_ptr<int>(new int(42)), g()); 호출시 new가 되고 shared_ptr에 등록되는 사이에 g가 불려 exception발생하면 leak이 생김
    // make_shared의 경우 내부적으로 control block과 new 가 동시에 호출되지만, new를 직접쓰는경우는 control block과 따로 호출되므로 overhead가 있음
    // 어떤 클래스가 custom new, delete를 를 정의햇을경우 make_shared에선 이를 호출할수 없기때문에 사용불가
    // control block에는 reference count와 weak reference count 두 정보를 저장
    // 주의!!       : make_shared와 new 에 따라 메모리 해제 시점이 달라짐
    // make_shared : control block과 T의 메모리를 함께 관리 -> refCount와 weakRefCount가 모두 0이 되어야만 control block과 T 메모리가 동시 해제됨
    // new         : refCount가 0이 될때 T메모리 해제, weakRefCount까지 0이 될때 control block 메모리 해제
    // => make_shared의 경우 shared_ptr이 모두 없어져 refCount가 0이되고 weak_ptr만 남아있어도 메모리에 남아있게 되어 비효율적임
    // => make_shared는 코드 중복, 예외, 속도에 유리함, make_shared와 new의 메모리 관리정책을 이해하고 적절하게 사용 필요

    std::shared_ptr<pthread_mutex_t> mutex = make_shared<pthread_mutex_t>(); // make_shared: default allocator, deallocator 사용
    std::shared_ptr<pthread_mutex_t> mutex1( new pthread_mutex_t() ); // allocator 만 지정
    std::shared_ptr<pthread_mutex_t> mutex2( new pthread_mutex_t(), pthread_mutex_unlock ); // allocator, deallocator 를 지정

    std::shared_ptr<int> intPtr = make_shared<int>();
    weak_ptr<int> weak_intPtr = intPtr;

    // MOVE
    // T&& 리턴, const가 붙으면 const T&& 리턴
    // const 객체에 std::move를 쓴다는게 허용이 되더라도 대부분의 경우 매우 이상한 경우임!!
    // string class에 'string&&' 생성자만 있고, 'const string&&' 생성자는 없기때문에, move를 하더라도 lvalue 복사 생성자('const string&') 호출됨
    string s1{ std::move( ( const string ) to_string( 0 ) ) }; // string( const basic_string& ) 호출 -> 이런식으로 const객체에 std::move를 쓰는건 이상한 케이스임
    string s2{ std::move( to_string( 0 ) ) };                  // string( basic_string&& ) 호출

    // FORWARD
    // std::forword : 인자가 rvalue일땐 rvalue 리턴, lvalue일땐 lvalue 리턴 : 두 파라미터 타입을 overloading
    // _Tp&& forward(typename remove_reference<_Tp>::type& __t)
    // _Tp&& forward(typename remove_reference<_Tp>::type&& __t)
    // 위 forward정의에서 lvalue에 대한 return type도 rvalue로 되어잇는데 이게 사실 rvalue로 casting 되어도 lvalue로 간주됨

    string&& lvalue2ralue = to_string( 11 ); // lvalue에 return type도 rvalue로 되어있는데, 사실 rvalue로 casting되어도 lvalue로 간주됨
    forward<string>( lvalue2ralue ); // 이 forward 함수가 lvalue 정의로 호출되는것을 알 수 있음

    // lvalue forward
    string lvalueStr = to_string( 0 );
    auto lvalueResult = std::forward<string>( lvalueStr );
    auto&& rvalueResult = std::forward<string>( std::move( lvalueStr ) ); // rvalue forward

    shared_ptr<Investment> investmentPtr = InvestmentFactory::createInvestment();

    return 0;
}
