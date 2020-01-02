#pragma once

class Base
{
public:
    virtual void m1()
    {
    }

    virtual void m1( int a )
    {
    }
};

class Derived : public Base
{
public:
    using Base::m1;
    virtual void m1() override
    {

    }
};

int main( void )
{
    Derived d;
    d.m1();
    d.m1(1); // 오버로딩된 메소드를 오버라이드하면 가려짐 (이럴땐 Derived에 using 을 써서 이름이 가려지지 않도록 해야한다.)
    return 0;
}