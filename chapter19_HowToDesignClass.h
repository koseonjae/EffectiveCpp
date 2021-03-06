#pragma once

class chapter19_HowToDesignClass
{
    // note: 클래스를 디자인할때 아래 항목들을 모두 고려하자
    // 1. 생성과 소멸 => 생성자 소멸자 설계
    // 2. 생성자와 복사 대입 연산자 설계
    // 3. 복사 생성자 설계
    // 4. 클래스의 불변속성 -> 생성자, 대입연산자, setter등에서 좌우됨
    // 5. 상속 계통망 -> 가상, 비가상을 결정 (특히 소멸자)
    // 6. 타입 변환 -> 암시적 또는 명시적 변환을 허용할 것인가
    // 7. 연산자 오버로딩 할 것인가
    // 8. 표준 함수의 허용 -> 복사생성자, 복사 대입연산자등이 필요없으면 delete 해버리자
    // 9. 멤버의 접근 권한과 friend 함수에 대한 고려
    // 10. 제공할 보장을 결정 -> 성능, 예외 안전성, 자원 사용(lock, 메몰) 등을 고려
    // 11. 일반성
    // 12. 꼭 필요한 타입인지 -> 꼭 필요한 클래스가 아니라면 템플릿 몇개를 더 정의하거나 비멤버 함수를 이용하자
};
