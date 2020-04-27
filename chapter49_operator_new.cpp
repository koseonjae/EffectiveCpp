#include <iostream>
#include <new>

using namespace std;

void outOfMem()
{
    cout << "default new handler" << endl;               // null handling의 여러가지 방법들
    throw bad_alloc();                              // 예외를 던지는 방법
    // std::set_new_handler( anotherNewHandler );   // 다른 new handler를 세팅하는 방법
    // std::set_new_handler( nullptr );             // null 세팅 방법
    // abort();                                     // exit이나 abort 호출
}

static void widgetNewHandler()
{
    cout << "WidgetNewHandler is called" << endl;
    throw bad_alloc();
}

template <typename T>
class SupportNewHandler
{
    class RAIIHandler final
    {
    public:
        explicit RAIIHandler( new_handler handler ) : h( handler )
        {
        }

        ~RAIIHandler()
        {
            std::set_new_handler( h );
        }

    private:
        std::new_handler h;
    };

public:
    static std::new_handler set_new_handler( std::new_handler handler )
    {
        std::new_handler oldHandler = m_handler;
        m_handler = handler;
        return oldHandler;
    }

    static void* operator new( size_t size )
    {
        RAIIHandler handler( std::set_new_handler( m_handler ) );
        return ::operator new( 5000000000000000L ); // return ::operator new( size; ); 라고 해야하지만 new의 exception을 위해
    }

private:
    static std::new_handler m_handler;
};

template <typename T> std::new_handler SupportNewHandler<T>::m_handler = nullptr;

class Widget : public SupportNewHandler<Widget>
{
public:
};

int main( void )
{
    std::set_new_handler( outOfMem );

    Widget::set_new_handler( widgetNewHandler );

    try
    {
        Widget* widget = new Widget();
    } catch( exception& ex )
    {
        cout << "widget operator new exception: " << ex.what() << endl;
    }

    try
    {
        int* bigData = new int[50000000000000L];
    } catch( bad_alloc& ex )
    {
        cout << "int new exception: " << ex.what() << endl;
    }

    return 0;
}
