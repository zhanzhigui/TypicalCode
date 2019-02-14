#pragma once
#include <iostream>
#include <memory>


class TestDeleteArrayPtr
{
public:
    TestDeleteArrayPtr()
    {
        
        int* ptr = new int[5];
        for (int i=0; i<5; ++i)
        {
            //ptr[i] = i;
            *ptr = i;
            ++ptr;
            //*spaceid_ptr = i;
        }
        ptr = ptr - 5;

        init(ptr, 5);
        delete []ptr;
        ptr = nullptr;

    }

    void init(const int* spaceid_ptr, const int count)
    {
        for (int i=0; i<count; ++i)
        {
            cout << spaceid_ptr[i] << endl;
        }
    }
};