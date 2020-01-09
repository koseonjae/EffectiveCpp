#include <iostream>

class B
{
public:
    void mf()
    {
        std::cout << "B::mf" << std::endl;
    }
};

class D : public B
{
public:
    void mf()
    {
        std::cout << "D::mf" << std::endl;
    }
};

int main( void )
{
    D d;
    B* b = &d;
    b->mf(); // note: non virtual을 재정의하면 B가 불릴지 D가 불릴지 모름
    return 0;
}