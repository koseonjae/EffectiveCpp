#pragma once

class chapter24_NoMemberMethodForTypeConversion
{
    // note: 어떤 함수에 들어가는 모든 매개변수에 대해서 타입 변환을 해 줄 필요가 있다면, 그 함수는 비멤버함수이어야 한다.
};

class Rational final
{
public:
    Rational( int numerator = 0, int denominator = 1 )
            : m_numerator( numerator ), m_denominator( denominator )
    {

    }

    ~Rational() = default;

    Rational( const Rational& ) = delete;

    Rational& operator=( const Rational& ) = delete;

//    const Rational operator*( const Rational& rhs ) const
//    {
//        return Rational( this->m_numerator * rhs.m_numerator, this->m_denominator * rhs.m_denominator );
//    }

    int numerator() const
    {
        return m_numerator;
    }

    int denominator() const
    {
        return m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};

const Rational operator*( const Rational& lhs, const Rational& rhs )
{
    return Rational( lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator() );
}
//
//int main( void )
//{
//    Rational rational1( 1, 1 );
//    Rational rational2 = rational1 * 2; // 이 로직은 멤버함수로도 호출 가능
//    Rational rational3 = 2 * rational1; // 멤버 함수로 선언된 operator* 에선 이 로직 호출 불가능
//}