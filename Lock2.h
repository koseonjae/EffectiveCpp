#pragma once

#include <pthread.h>
#include <memory>
#include <cstdio>

using namespace std;

class Lock2
{
public:
    Lock2( pthread_mutex_t *mutex ) : m_mutex( mutex )
    {
        printf( "Lock2::Constructor is called\n" );
        pthread_mutex_lock( m_mutex.get() );
    }

    ~Lock2()
    {
        printf( "Lock2::Destructor is called\n" );
    }

    Lock2( const Lock2& ) = delete;

    Lock2& operator=( const Lock2& ) = delete;

private:
    std::shared_ptr<pthread_mutex_t> m_mutex;
};
