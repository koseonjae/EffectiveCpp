#include <iostream>

using namespace std;

template <typename T>
class Rational;

template <typename T>
const Rational<T> doMultiplay( const Rational<T>& lhs, const Rational<T>& rhs ) // operator*는 Rational클래스의 멤버함수가 아닌 비멤버 함수이다! (friend 선언)
{
    return Rational( lhs.getX() * rhs.getX(), lhs.getY() * rhs.getY() );
}

template <typename T>
class Rational
{
public:
    Rational( T x = 0, T y = 1 ) : x( x ), y( y )
    {
    }

    friend const Rational operator*( const Rational& lhs, const Rational& rhs ) // operator*는 Rational클래스의 멤버함수가 아닌 비멤버 함수이다! (friend 선언)
    {
        return doMultiplay( lhs, rhs ); // 인라인화를 최소화하기 위해 doMultiplay를 따로 정의한다.
    }

    T getX() const
    {
        return x;
    }

    T getY() const
    {
        return y;
    }

private:
    T x;
    T y;
};

int main( void )
{
    Rational a( 2, 1 );
    Rational result = a * 2;
    cout << result.getX() << ", " << result.getY() << endl;
    return 0;
}
