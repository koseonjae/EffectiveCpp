#include <iostream>
#include <vector>

template <typename C>
void print2nd( const C& container )
{
    if( container.size() >= 2 )
    {
        typename C::const_iterator iter( container.begin() ); // note: C::const_iterator 같이 템플릿 매개변수 + 그 매개변수의 중첩 클래스를 중첩의존이름(nested dependent name)이라고 한다.
        iter++;
    }
    typename C::const_iterator a; // 중첩 의존 이름 => typename을 붙이지 않으면 타입으로 간주하지 않
    C b; // 의존 이름
}

template <typename iterT>
void workWithIterator( iterT iter )
{
    typedef typename std::iterator_traits<iterT>::value_type valueType;
    valueType temp( *iter );
}

int main( void )
{
    std::string a;
    print2nd( a );
    return 0;
}
