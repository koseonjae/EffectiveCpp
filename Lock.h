#pragma once

#include <iostream>
#include <pthread.h>
#include <memory>

using namespace std;

class Lock final
{
public:
    explicit Lock( pthread_mutex_t *mutex ) : m_mutex( mutex, pthread_mutex_unlock )
    {
        cout << "Lock::Constructor" << endl;
        pthread_mutex_lock( m_mutex.get() );
    }

    ~Lock()
    {
        cout << "Lock::Destructor" << endl;
    }

    Lock( const Lock& rhs ) = delete;

    Lock& operator=( const Lock& rhs ) = delete;

    pthread_mutex_t *get() // 자원관리 객체가 제공하는 명시적 변환 함수
    {
        return m_mutex.get();
    }

    operator pthread_mutex_t *() const
    {
        return m_mutex.get();
    }

private:
    shared_ptr<pthread_mutex_t> m_mutex;
};
