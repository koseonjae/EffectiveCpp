#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Iter, typename DistT>
void doAdvance( Iter& iter, DistT d, random_access_iterator_tag __unused )
{
    iter += d;
}

template <typename Iter, typename DistT>
void doAdvance( Iter& iter, DistT d, bidirectional_iterator_tag __unused )
{
    if( d >= 0 )
    {
        while( d-- )
        {
            ++iter;
        }
    }
    else
    {
        while( d++ )
        {
            --iter;
        }
    }
}

template <typename Iter, typename DistT>
void doAdvance( Iter& iter, DistT d, forward_iterator_tag __unused )
{
    if( d < 0 )
    {
        throw out_of_range( "negative distance" );
    }
    while( d-- )
    {
        ++iter;
    }
}

int main( void )
{
    vector<int> a{ 1, 2, 3 };
    
    auto iter = a.begin(); // vector의 iterator는 "typedef random_access_iterator_tag iterator_category;" 를 정의한다.

    doAdvance( iter, 2, iterator_traits<vector<int>::iterator>::iterator_category() ); // iterator_traits<vector<int>::iterator>::iterator_category() 는 컴파일 타임에 결정되는 값

    iterator_traits<vector<int>::iterator>::value_type intVal = 1;

    list<int> l{ 1, 2, 3 };
    auto listIter = l.begin();

    doAdvance( listIter, 2, iterator_traits<list<int>::iterator>::iterator_category() );

    return 0;
}