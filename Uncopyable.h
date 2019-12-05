#pragma once

class Uncopyable
{
protected:
    Uncopyable()
    {
    }

    ~Uncopyable()
    {
    }

private:
    Uncopyable( const Uncopyable &rhs );

    Uncopyable &operator=( const Uncopyable &rhs );
};
