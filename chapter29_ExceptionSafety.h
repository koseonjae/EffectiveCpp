#pragma once

#include <iostream>

using namespace std;

int doSomething_1() noexcept
{
    // noexcept는 예외를 던지지 않겠단 뜻이 아니다
    // 지정되지 않은 예외가 발생했을 경우에 실행되는 처리자인 unexpected 함수가 호출되어야 한다는 뜻
    throw out_of_range( "" );
}

class Image
{
public:
    Image( istream& image )
    {
    }
};

class PrettyMenu
{
public:
    void changeBackground_bad_example( istream& image )
    {
        m_mutex.lock();
        imageChanges++; // new 에서 예외발생하면 바뀌지도 않았는데 count만 증가함
        bgPtr = new Image( image );
        m_mutex.unlock(); // new 예외발생하면 unlock 되지 않음
    }

    void changeBackground( istream& image )
    {
        std::lock_guard<mutex> lock( m_mutex );
        bg.reset( new Image( image ) ); // todo: reset과 make_shared의 차이를 알아보자
        imageChanges++;
    }

private:
    int imageChanges;
    mutex m_mutex;
    Image *bgPtr;
    shared_ptr<Image> bg;
};
