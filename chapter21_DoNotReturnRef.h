#pragma once

class chapter21_DoNotReturnRef
{
    // note: 함수에서 객체를 반환할 경우에 참조자를 반환하지 말자
    // 파라미터일때는 const T& 가 효율적이지만 반환타입에서는 매우 그렇지 못하다
    // 지역객체의 참조자, 지역객체의 포인터를 반환하는 함수는 어떤 함수든지 프로그램의 핵폭탄임
    // local static 객체의 참조자를 반환하는것도 멀티쓰레드로가면 위험해짐
};
