/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file.
 *
 * This provides tests for the iterator.
 */

#include "catch.hpp"
#include "../ChunkList.h"
#include "unit_utils.h"

TEST_CASE("Iterator Tests") {
    SECTION("Test basic Iterator - 2pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist and see that the data matches
        ChunkList<int> list(data, len);
        list.ResetIterator();
        for (int i = 0; i < list.GetLength(); i++) {
            REQUIRE(list.GetNextItem() == data[i]);
        }
    }
    SECTION("Test Iterator with Contains - 2pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist and see that the data matches
        ChunkList<int> list(data, len);
        list.ResetIterator();
        for (int i = 0; i < list.GetLength(); i++) {
            REQUIRE(list.Contains(data[i]));
            REQUIRE(!list.Contains(-1));
            REQUIRE(list.GetNextItem() == data[i]);
        }
    }
    SECTION("Test Iterator after value removal - 2pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist
        ChunkList<int> list(data, len);

        // Remove values one at a time in a random order
        // Just using default seed for rand.
        int currLen = len;
        for (int i = 0; i < 100; i++) {
            int randValue = data[rand()%currLen];  // pick a random value to remove

            // remove from both lists
            remove_value(randValue, data, currLen);
            list.Remove(randValue);

            // Make sure things still match
            list.ResetIterator();
            for (int j = 0; j < list.GetLength(); j++) {
                REQUIRE(list.GetNextItem() == data[j]);
            }

            currLen--;
        }
    }
    SECTION("Test Constructor initializes iterator - 2pt") {
        // Load some data into a normal array
        int data[1000];
        int len;
        init_arr("test_data/dataset_constructor.txt", data, len);

        // Load the data into a Chunklist and see that the data matches
        ChunkList<int> list(data, len);
        for (int i = 0; i < list.GetLength(); i++) {
            REQUIRE(list.GetNextItem() == data[i]);
        }
    }
    SECTION("Test empty list - 1pt") {
        ChunkList<int> list;
        REQUIRE_THROWS(list.GetNextItem(), IteratorOutOfBounds());
    }
    SECTION("Test out of bounds - 2pt") {
        for (int i = 0; i < 10; i++) {
            ChunkList<int> list;
            // fill with values 0 to i
            for (int j = 0; j < i+1; j++)
                list.Append(j);

            // iterate all the way to the end
            list.ResetIterator();
            for (int j = 0; j < list.GetLength(); j++)
                list.GetNextItem();

            // check that we are out of bounds
            REQUIRE_THROWS(list.GetNextItem(), IteratorOutOfBounds());
        }
    }
}