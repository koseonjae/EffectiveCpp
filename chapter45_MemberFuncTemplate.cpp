#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::CopyConstructor" << endl;
    }

    virtual ~Base()
    {
        cout << "Base::Destructor" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base()
    {
        cout << "Derived::Constructor" << endl;
    }

    virtual ~Derived()
    {
        cout << "Derived::Destructor" << endl;
    }
};

template <typename T>
class SmartPtr
{
public:
    explicit SmartPtr() = default;

    explicit SmartPtr( T* ptr ) : ptr( ptr )
    {
    }

    template <typename U>
    SmartPtr( const SmartPtr<U>& rhs )
    {

    }

    virtual ~SmartPtr()
    {
        delete ptr;
    }

private:
    T* ptr;
};

int main( void )
{

    int a = 1;
    int* ptr = &a;
    const int* ptr2 = ptr; // non const to const

    // ========

    SmartPtr<Base> intPtr{ SmartPtr<Derived>() };

    // ========



    return 0;
}
