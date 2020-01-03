#pragma once

namespace ForwardDeclaration
{
    // note: 이 전방 선언의 문제점
    // 첫번째 문제로, std::string을 제대로 전방선언하지 않은것. 템플릿을 제대로 가져와야함
    // 그래도 표준 라이브러리는 왠만하면 컴파일 병목을 일으키지 않으니 문제 없음
    namespace std { class string; } // typedef basic_string<char>를 선언한것 뿐임

    class Data;

    class Address;

    class Person
    {
    public:
        Person( const std::string& name, const Data& data, const Address& address );
    };

    void example_main( void )
    {
        int x;
//        Person p("", ); // 할당하려면 컴파일러가 정의된 정보 봐야함
    }
}

// -----------
// pImpl 관용구
// -----------

#include <iostream>
#include <string>
#include <memory>

class PersonImpl;

class Date;

class Address;

class Person
{
public:
    Person( const std::string& name, const Date& data, const Address& address );

private:
    // note: 구현 클래스(pImpl)에 대한 포인터만 가지고 있다.
    // Person 사용자는 내부 세부사항과 갈라서게 되고, 구현 클래스(personImpl을 바꿔도 사용자측에선 재컴파일 할 필요 없다)
    // 정의부에 대한 의존성 -> 선언부에 대한 의존성으로 바
    std::shared_ptr<PersonImpl> pImpl;
};

// note 정리
// 객체 참조자 및 포인터로 충분한 경우에는 객체를 직접 쓰지 않습니다. (컴파일러가 객체가 아닌 포인터 사이즈만 고려하도록)
// 할 수 있으면 클래스 정의 대신 클래스 선언에 최대한 의존하도록 만듭니다.
// 선언부 헤더와 정의부 헤더를 나누자 (라이브러리 사용자가 선언부 헤더만 include해서 사용할 수 있도록 한다.
// pimpl 말고 인터페이스 클래스를 만드는 방법도 있음! 가상함수 소멸자와 인터페이스를 구성하는 순수 가상 함수만 들어잇는 클래스

class EmployeeInterface
{
public:
    virtual ~EmployeeInterface();

    virtual std::string name() const = 0;

    virtual std::string address() const = 0;

    static std::shared_ptr<EmployeeInterface> create( const std::string& name, const std::string& address );
};

class Employee : public EmployeeInterface
{
    ~Employee();
};

void interface_example()
{
//    std::shared_ptr <EmployeeInterface> person = EmployeeInterface::create( "", "" );
}