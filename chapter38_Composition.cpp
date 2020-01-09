#include <iostream>
#include <list>

// note: has-a                      : 사물을 본 뜬 객체(사람, 이동수단, 주소록) 등에서의 composition
// note: is-implemented-in-terms-of : 시스템 구현을 위한 인공물(버퍼, 뮤텍스, 탐색트리) 등에서의 composition

template <typename T>
class WrongSet : public std::list<T>
{
    // note: list는 중복 원소를 허용하지만 Set은 허용하지 않는다.
    // list is-a set 이라는 is-a 관계가 성립되지 않으므로 상속은 올바른 방법이 아님
};

template <typename T>
class Set
{
public:
    bool member( const T& rhs )
    {
        return std::find( list.begin(), list.end(), rhs ) != list.end();
    }

    void insert( const T& rhs )
    {
        if( !member( rhs ) )
        {
            list.push_back( rhs );
        }
    }

    void remove( const T& rhs )
    {
        typename std::list<T>::iterator it = std::find( list.begin(), list.end(), rhs );
        if( it != list.end() )
        {
            list.erase( it );
        }
    }

    int size() const
    {
        return list.size();
    }

private:
    std::list<T> list; // Set is implemented in terms of list
};

int main( void )
{
    Set<int> a;
    a.insert(3);
    a.remove(4);
    a.size();
}
