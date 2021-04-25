// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(10);

        // Test
        bi = bi.times10(3);

        // Verify
        assert(bi == 10000);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(99);

        // Test
        bi = bi.times10(2);

        // Verify
        assert(bi == 9900);  
    } 
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(8990);

        // Test
        bi = bi.times10(5);

        // Verify
        assert(bi == 899000000);  
    }  
    std::cout << "Done testing times_10" << std::endl;
}

