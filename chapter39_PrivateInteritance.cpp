#include <iostream>

// note: private 상속 : is-implemented-in-terms-of 와 동일한 개념이다.
// 즉 설계(design)상의 이점이 아닌, 단지 Derived 가 Base의 구현을 사용하기위해 사용한다.
// is-implemented-in-terms-of와 private 상속중 어떤것을 골라야 하는가?
// 할 수 잇으면 is-implemented-in-terms-of를 쓰자.
// 꼭 써야하는 경우에만 private 상속 쓰자( 오버라이딩이나 비공개 멤버 접근이 필요할 경우 )
// -> 기본 클래스의 protected에 접근 해야 하는 경우 or 가상함수를 재정의 해야 하는 경우가 있다.

class Timer
{
public:
    Timer( int tickMs )
    {
    }

    virtual ~Timer() = default;

    virtual void onTick( void ) = 0; // 상속해서 onTick에 무엇을 할지 정해줘야하는 구조
};

class Widget : private Timer
{
public :
    Widget() : Timer::Timer( 1 )
    {
    }

private:
    virtual void onTick( void ) override final
    {
    }
};

class DerivedWidget : public Widget
{
public:
    DerivedWidget() : Widget::Widget()
    {
    }

private:
//    virtual void onTick( void ) override // note: Widget1 에서 onTick을 재정의 못하도록 final로 막았
//    {
//
//    }
};

int main( void )
{
    Widget widget;
    DerivedWidget derivedWidget;
    return 0;
}
