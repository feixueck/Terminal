﻿#include "pch.h"
#include "Class.h"

namespace winrt::RuntimeComponent1::implementation
{
    int32_t Class::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Class::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    int32_t Class::DoTheThing()
    {
        throw 42;
    }
}
