#include <iostream>

using namespace std;

class CompanyA
{
public:
    void sendEncrypted( const string& msg )
    {
    }

public:
    void sendClear( const string& msg )
    {
    }
};

class CompanyB
{
public:
    void sendClear( const string& msg )
    {
    }

    void sendEncrypted( const string& msg )
    {
    }
};

class CompanyZ
{
public:
    void sendEncrypted( const string& msg ) // note: sendClear를 제공하지 않음
    {
    }
};

class MsgInfo
{
};

template <typename Company>
class MessageSender
{
public:
    void sendClear( const MsgInfo& info )
    {
        string msg;
        Company c;
        c.sendClear( msg );
    }

    void sendSecret( const MsgInfo& info )
    {
        string msg;
        Company c;
        c.sendEncrypted( msg );
    }
};

template <>
class MessageSender<CompanyZ> // 완전 템플릿 특수화
{
public:
    void sendEncryptedMsg( const MsgInfo& info )
    {

    }
};

template <typename Company>
class LoggingMessageSender : public MessageSender<Company>
{
//    using MessageSender<Company>::sendClear; // note: 2. using keyword를 통해 기본 클래스의 이름을 파생 클래스 유효범위에 끌어올 수 있다.
public:
    void sendClearMsg( const MsgInfo& info )
    {
        // sendClear(info); // note: c++ 컴파일러는 템플릿으로 만들어진 기본 클래스를 뒤져서 상속된 이름을 찾는것을 거부한다.
//        this->sendClear( info ); // note: 1. this를 붙여서 찾도록 할 수 있다. (추천)
//        MessageSender<Company>::sendClear( info ); // note: 3. 명시적으로 지정 -> 가상함수 바인딩이 무시되기 때문에 비추
    }
};

int main( void )
{
    MessageSender<CompanyA> a;
    MsgInfo msgInfo;
    a.sendClear( msgInfo );

    LoggingMessageSender<CompanyZ> z;
    z.sendClearMsg( msgInfo ); // note: 템플릿 특수화가 들어가는 순간,
    return 0;
}
