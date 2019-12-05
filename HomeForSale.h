#pragma once

#include "Uncopyable.h"

class HomeForSale
{
public:
    HomeForSale() = default;

    virtual ~HomeForSale() = default;

    HomeForSale( const HomeForSale &rhs ) = delete;

    HomeForSale &operator=( const HomeForSale &rhs ) = delete;
};
