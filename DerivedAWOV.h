#pragma once

#include "AWOV.h"
#include <iostream>

using namespace std;

class DerivedAWOV : public AWOV
{
public:
    ~DerivedAWOV()
    {
        cout << "DerivedAWOV::Destructor" << endl;
    }
};
