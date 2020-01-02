#pragma once

class AirPlane
{
public:
    virtual void fly() = 0;
};

void AirPlane::fly()
{
    // 순수가상함수에도 기본 구현을 제공할 수 있다.
}

class ModelA : public AirPlane
{
public:
    virtual void fly() override
    {
        AirPlane::fly(); // 순수가상함수의 기본 구현을 사용할 수 있다.
    }
};

int main( void )
{
    // note
    // 상속되어도 불변의 동작이 되어야 하는 함수는 비가상함수로 만든다.
    // 인터페이스를 제공할지, 구현이 있는 가상함수를 제공할지를 상황에 맞게 제공한다.
    // 가상함수 클래스라고해서 생기는 오버헤드는 작다.
    ModelA b;
    return 0;
}