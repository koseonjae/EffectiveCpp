#include <iostream>

// 중복 참조의 첫번째 고민 : 상속 클래스에 같은 이름이 있을때 모호성 발생
// 중복 함수 호출 프로세스 : best-match 함수인지 체크(최적으로 일치하는지 체크)한 후에, 접근 가능성을 따진다. (접근 가능성은 나중에 따지는 구조임)

// 다이아몬드 상속
// a
// b c // b, c는 a를 상속한다
// d   // d는 b와 c를 상속한다.
// 이런식으로 다이아몬드 상속이 잇을 경우 d는 a의 변수를 두개씩 갖게됨
// 이걸 막기 위한 방법은 가상상속 사용
// 가상상속은 속도가 느리고 크기도 크며 초기화 규칙에 대한 복잡성이 증가해서 별로다. 직관성도 떨어짐

// 가상 상속을 할 때의 두가지 고려사항
// 가상 기본 클래스로부터 파생클래스가 생겼을때, 파생클래스는 가상 기본 클래스와의 거리에 상관없이 존재를 염두해두고 잇어야 한다 ?
// 파생 클래스는 가상 기본 클래스의 초기화를 떠맡아야 한다.

class IPerson
{
public:
    virtual ~IPerson() = default;

    virtual std::string name() const = 0;

    virtual std::string birthDate() const = 0;
};

class PersonInfo
{
public:
    explicit PersonInfo( int databaseId ) // database로부터 name, birthData를 가져오는 함수
    {
    }

    virtual ~PersonInfo() = default;

    virtual std::string name() const
    {
        return std::string( "name" );
    }

    virtual std::string birthDate() const
    {
        return std::string( "12345" );
    }
};

// note: CPerson은 IPerson의 인터페이스를 사용하며, PersonInfo의 구현을 사용한다.
class CPerson : public IPerson, private PersonInfo
{
public:
    explicit CPerson( int databaseId ) : PersonInfo( databaseId )
    {
    }

    ~CPerson() override = default;

    std::string name() const override
    {
        return PersonInfo::name();
    }

    std::string birthDate() const override
    {
        return PersonInfo::birthDate();
    }
};

int main( void )
{
    std::shared_ptr<IPerson> person = std::make_shared<CPerson>( 1 );
    person->name();
    person->birthDate();
    return 0;
}
