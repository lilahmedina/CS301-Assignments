/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file.
 *
 * The purpose of this file is to test the constructor functions.
 */
#include "catch.hpp"
#include <fstream>
#include "../ChunkList.h"
#include "unit_utils.h"


TEST_CASE("Constructor Tests") {

    SECTION("Test that default length is 0 - 2pt") {
        ChunkList<int> list;
        REQUIRE(list.GetLength() == 0);
    }
    SECTION("Testing ChunkList(int[], int) - 3pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist and see that the data matches
        ChunkList<int> list(data, len);

        // Make sure length matches the length from the file
        if (list.GetLength() != len) {
            INFO("Length does not match.  Expected " << len << " elements. Len is " << list.GetLength());
            FAIL();
        }

        for (int i = 0; i < list.GetLength(); i++) {
            REQUIRE(list.Contains(data[i]));
            REQUIRE(!list.Contains(-data[i]));
        }
    }
    SECTION("Testing bad array size - 2pt") {
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);
        REQUIRE_THROWS(ChunkList<int>(data, -100),InvalidArrayLength());
    }
}