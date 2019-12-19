//
// Created by 고선재 on 2019-12-20.
//

#include "chapter25_Swap.h"

int main( void )
{
    using std::swap;
    PhoneStuff::Phone<int> a;
    PhoneStuff::Phone<int> b;
    swap( a, b ); // 이름 탐색 규칙에 의해 std::swap이 아닌 PhoneStuff::swap을 호출하게 된다.
    // 이름 탐색 규칙
    // 전역 or namespace를 먼저 찾는다
    // using 선언을 하였으므로 그 다음에 std::swap을 찾는다. -> 여기에서 특수화 버전이 잇으면 그것을 사용하고 없으면 일반 std::swap을 호출한다.
    // std::swap(a, b); 처럼 한정자를 붙이면 안됨 !! -> 이렇기 때문에 std::swap을 완전히 특수화 하는게 중요함
}