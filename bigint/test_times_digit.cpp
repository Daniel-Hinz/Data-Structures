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
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(100);

        // Test
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 200);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1999);

        // Test
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 9995);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(2001);

        // Test
        bi = bi.timesDigit(2001);

        // Verify
        assert(bi == 4004001);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(50000);

        // Test
        bi = bi.timesDigit(3456);

        // Verify
        assert(bi == 172800000);
    }
    std::cout << "Done testing bigint * digit" << std::endl;
}
