/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file.
 *
 * The purpose of this file is to test the GetIndex function.
 */

#include "catch.hpp"
#include <fstream>
#include <iostream>
#include "../ChunkList.h"
#include "unit_utils.h"

TEST_CASE("GetIndex Tests") {

    SECTION("Test basic GetIndex - 3pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist and see that the data matches
        ChunkList<int> list(data, len);
        for (int i = 0; i < list.GetLength(); i++) {
            REQUIRE(list.GetIndex(i) == data[i]);
        }
    }
    SECTION("Test GetIndex after value removal - 2pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist
        ChunkList<int> list(data, len);

        // Remove values one at a time in a random order
        // Just using default seed for rand.
        int currLen = len;
        for (int i = 0; i < len; i++) {
            int randValue = data[rand()%currLen];  // pick a "random" value to remove

            // remove from both lists
            remove_value(randValue, data, currLen);
            list.Remove(randValue);

            for (int j = 0; j < list.GetLength(); j++) {
                if (list.GetIndex(j) != data[j]) {
                    INFO("Error after trying to remove " << randValue);
                    REQUIRE(list.GetIndex(j) == data[j]);
                }
            }

            currLen--;
        }
    }
    SECTION("Test index < 0 - 2pt") {
        ChunkList<int> list;
        list.Append(42); // appending the meaning of life
        REQUIRE_THROWS(list.GetIndex(-100), IndexOutOfBounds());
    }
    SECTION("Test index > length - 2pt") {
        ChunkList<int> list;
        list.Append(42); // appending the meaning of life
        REQUIRE_THROWS(list.GetIndex(1000), IndexOutOfBounds());
    }
    SECTION("Test empty list - 2pt") {
        ChunkList<int> list;
        REQUIRE_THROWS(list.GetIndex(0), IndexOutOfBounds());
        REQUIRE_THROWS(list.GetIndex(10), IndexOutOfBounds());
        REQUIRE_THROWS(list.GetIndex(-10), IndexOutOfBounds());
    }
}