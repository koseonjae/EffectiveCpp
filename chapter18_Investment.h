#pragma once

#include <memory>

// note: 인터페이스 사용자가 제대로 쓰기엔 쉽게, 잘못 쓰기엔 어렵게 설계하자
// 사용자 실수의 종류를 모두 고려하여 설계한다.
// 전달순서 -> 타입을 객체화
// 메모리릭 -> 객체 반환의 경우shared_ptr을 리턴하도록
// 타입안정성 -> 암시적 변환에 유의 (막으려면 explicit)
// const -> operator* 등에서 a * b = c 가 불가능하도록
// 일관성 -> 번듯한 이유가 없다면 기본제공타입처럼 동작하게 하자 (일관성있게 짜자)
// 컴파일 -> 잘못짜면 컴파일이 안돼게 하자, 컴파일이 되는 코드는 제대로 동작하는것을 보장하게 하자
//
//class chapter18_Investment
//{
//private:
//    chapter18_Investment() = default;
//
//    virtual ~chapter18_Investment() = default;
//};
//
//class InvestmentFactory
//{
//public:
//    static std::shared_ptr<chapter18_Investment> createInvestment()
//    {
//        return std::make_shared<chapter18_Investment>();
//    }
//};
