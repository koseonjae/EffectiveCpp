class Oper
{
public:
    bool operator>( int a )
    {
        return true;
    }
};

class Widget
{
public:
    Oper size()
    {
        return oper;
    }

private:
    Oper oper;
};

template <typename T>
void doProcessing( T& w )
{
    T somenastywidget;
    if( w.size() > 10 )
    {
        // note: T 타입은 size의 return으로 bool operator>(int)를 만족시키는 타입만 반환하면 된다.
        // 굳이 정수 타입을 반환할 필요가 없음: 유효한 타입만 반환하면
    }
}

int main( void )
{
    Widget w;
    doProcessing( w ); // note: 템플릿이 호출될때 doProcessing이 Widget에 대한 소스를 생성 => 컴파일 타임 다형성

    // 런타임 다형성      : 가상함수의 호출이 런타임에 결정되는 것 (실제 메모리의 객체가 어떤 타입인지에 따라)
    // 컴파일 타임 다형성  : 템플릿의 인스턴스화가 컴파일 타임에 일어남
    return 0;
}