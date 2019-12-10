#pragma once

#include <memory>

class Investment
{
private:
    Investment() = default;

    virtual ~Investment() = default;
};

class InvestmentFactory
{
public:
    static std::shared_ptr<Investment> createInvestment()
    {
        return std::make_shared<Investment>();
    }
};
