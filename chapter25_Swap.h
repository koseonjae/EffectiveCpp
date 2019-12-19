#pragma once

#include <iostream>
#include <vector>

// ----------------------------------
// 클래스 템플릿의 부분 특수화
// ----------------------------------

// widget은 widgetImpl 변수만 갖고있고, WidgetImpl이 굉장히 많은 데이터를 갖고 있다고 가정한다.
// pimpl 포인터만 바꾸면되는데, std::Swap을 쓰면 객체 복사가 세번이나 일어나서 비효율적임
// 이럴 경우에 swap을 특수화 하는 방법
class WidgetImpl
{
    int a, b, c;
    std::vector<double> d;
};

class Widget
{
public:
    void swap( Widget& rhs )
    {
        std::swap( pimpl, rhs.pimpl );
    }

private:
    WidgetImpl *pimpl;
};

namespace std
{
    // 컴파일러에게 클래스 템플릿 특수화를 알려주는 부분
    template <>
    void swap<Widget>( Widget& a, Widget& b ) noexcept( is_nothrow_move_constructible<Widget>::value && is_nothrow_move_assignable<Widget>::value )
    {
        a.swap( b );
    }
}

// -----------------------------------------------
// 함수 템플릿의 부분 특수화는 c++에서 허용되지 않는다.
// -----------------------------------------------

template <typename T>
class ClockImpl
{
};

template <typename T>
class Clock
{
public:
    void swap( Clock<T>& rhs )
    {
        std::swap( pimpl, rhs.pimpl );
    }

private:
    ClockImpl<T> *pimpl;
};

namespace std
{
    // ---------------------------
    // 부분 특수화 우회를 위한 오버로드 버전
    // ---------------------------
    template <typename T>
    void swap( Clock<T>& a, Clock<T>& b )
    {
        a.swap( b );
    }

    // 아래 예제처럼 함수 템플릿의 부분특수화는 허용되지 않음: 'Function template partial specialization is not allowed' 라는 에러문구가 나옴
//    template <typename T>
//    void swap<Clock<T>>( Clock<T>& a, Clock<T>& b )
//    {
//        a.swap( b );
//    }
}

// --------------------------------------------------------------------
// std에서 뭘 하지 말고 swap을 하고싶은 class와 같은 namespace에 비멤버 함수를 정의하자
// --------------------------------------------------------------------
namespace PhoneStuff
{
    template <typename T>
    class PhoneImpl
    {
    };

    template <typename T>
    class Phone
    {
    public:
        void swap( Phone<T>& rhs )
        {
            std::swap( pimpl, rhs.pimpl );
        }

    private:
        PhoneImpl<T> *pimpl;
    };

    template <typename T>
    void swap( Phone<T>& a, Phone<T>& b )
    {
        a.swap( b );
    }
}
