// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  
        assert(digit == 4);
    }

    {
        // Setup
        bigint bi(60);

        // Test
        int digit = bi[1];

        // Verify
        assert(bi    == 60);  
        assert(digit == 6);
    }

    {
        // Setup
        bigint bi(45678);

        // Test
        int digit = bi[3];

        // Verify
        assert(bi    == 45678);
        assert(digit == 5);
    }

    {
        // Setup
        bigint bi(123);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi    == 123); 
        assert(digit == 3);
    }

    {
        // Setup
        bigint bi(40000);

        // Test
        int digit = bi[4];

        // Verify
        assert(bi    == 40000);  
        assert(digit == 4);
    }

    std::cout << "Done testing subscript." << std::endl;
}

