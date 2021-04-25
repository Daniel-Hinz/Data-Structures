// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        // VERY INCOMPLETE set of tests.

        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //-------------------------------------------------------
      // Setup fixture
      bigint left(23456);
      bigint right(23456);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 23456);
      assert(right  == 23456);
      assert(result == 46912);
    }
    {
      //-------------------------------------------------------
      // Setup fixture
      bigint left(11111111111);
      bigint right(3);
      bigint result;

      // Test
      result = left + right;
      
      // Verify
      assert(left   == 11111111111);
      assert(right  == 3);
      assert(result == 11111111114);
      
    }
    {
      //-------------------------------------------------------
      // Setup fixture
      bigint left(99999);
      bigint right(2);
      bigint result;

      //Test
      result = left + right;

      // Verify
      assert(left   == 99999);
      assert(right  == 2);
      assert(result == 100001);
    }
    std::cout << "Done with testing addition." << std::endl;
}

