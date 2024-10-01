/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file or use the ChunkList_demo.cpp file.
 *
 * The purpose of this file is to test the append and remove functions.
 */

#include "catch.hpp"
#include <fstream>
#include "../ChunkList.h"


TEST_CASE("Append Remove Tests") {

    SECTION("Basic Append - 3pt") {
        ChunkList<int> list;

        int numVals = 80;
        for (int i = 0; i < numVals; i++) {
            list.Append(i);
        }
        // Check Length and load factor after Appends
        REQUIRE(list.GetLength() == numVals);
        REQUIRE(list.LoadFactor() == 1.0);

        // Check if elements are added
        for (int i = 0; i < numVals; i++) {
            if (!list.Contains(i)) {
                INFO(i << " not in list");
                FAIL();
            }
        }
    }
    SECTION("Remove from empty list - 2pt") {
        ChunkList<int> list;
        REQUIRE_THROWS(list.Remove(rand()%1000), EmptyList());
    }
    SECTION("Remove half from middle node - 2pt") {
        ChunkList<int> list;
        // Create 4 chunks
        int numChks = 4;
        for (int i = 0; i < numChks; i++) {
            for (int j = 0; j < ARRAY_SIZE; j++) {
                list.Append(i);
            }
        }

        // Remove half of the 2's
        for (int j = 0; j < ARRAY_SIZE/2; j++) {
            list.Remove(2);
        }

        // Check load factor after removing half the values
        double totalSpace = numChks*ARRAY_SIZE;
        double alpha = (totalSpace-double(ARRAY_SIZE)/2)/totalSpace;
        REQUIRE(list.LoadFactor() == alpha);
    }
    SECTION("Remove middle node - 3pt") {
        ChunkList<int> list;
        // Create 4 chunks
        int numChks = 4;
        for (int i = 0; i < numChks; i++) {
            for (int j = 0; j < ARRAY_SIZE; j++) {
                list.Append(i);
            }
        }

        // Remove all of the twos
        for (int j = 0; j < ARRAY_SIZE; j++) {
            list.Remove(2);
        }

        // Should be load factor of 1.0
        REQUIRE(list.LoadFactor() == 1.0);

    }
    SECTION("Remove head node - 3pt") {
        ChunkList<int> list;
        // Create 4 chunks
        int numChks = 4;
        for (int i = 0; i < numChks; i++) {
            for (int j = 0; j < ARRAY_SIZE; j++) {
                list.Append(i);
            }
        }

        // Remove all of the 0's
        for (int j = 0; j < ARRAY_SIZE; j++) {
            list.Remove(0);
        }

        // Should be load factor of 1.0
        REQUIRE(list.LoadFactor() == 1.0);
    }
    SECTION("Remove last node - 3pt") {
        ChunkList<int> list;
        // Create 4 chunks
        int numChks = 4;
        for (int i = 0; i < numChks; i++) {
            for (int j = 0; j < ARRAY_SIZE; j++) {
                list.Append(i);
            }
        }

        // Remove all of the 3's
        for (int j = 0; j < ARRAY_SIZE; j++) {
            list.Remove(3);
        }

        // Should be load factor of 1.0
        REQUIRE(list.LoadFactor() == 1.0);
    }
    SECTION("Remove stress test - 3pt") {
        ChunkList<int> list;
        // Create 100 chunks
        int numChks = 100;
        int len = numChks*ARRAY_SIZE;

        int* values = new int[numChks*ARRAY_SIZE];
        for (int i = 0; i < len; i++) {
            values[i] = i;
            list.Append(i);
        }

        // Randomly remove one value one at a time and check the load factor
        // Purposely leave one element in each chunk
        int *leftovers = new int[numChks];
        int k = 0;
        for (int i = 0; i < numChks; i++) {
            int nodeValues[8];

            // Node values
            for (int j = 0; j < ARRAY_SIZE; j++) {
                nodeValues[j] = values[i*ARRAY_SIZE + j];
            }

            // shuffle to randomize remove order
            for (int j = 0; j < ARRAY_SIZE; j++) {
                int ind1 = rand()%ARRAY_SIZE;
                int ind2 = rand()%ARRAY_SIZE;
                swap(nodeValues[ind1], nodeValues[ind2]);
            }
            leftovers[k++] = nodeValues[7]; // leftover value
            
            // Remove all values except the leftover value
            for (int j = 0; j < ARRAY_SIZE - 1; j++) {
                list.Remove(nodeValues[j]);
                len--;
                REQUIRE(list.GetLength() == len);
                REQUIRE(list.LoadFactor() == static_cast<double>(len) / (numChks * ARRAY_SIZE));
            }
        }

        // shuffle to leftovers remove order
        for (int j = 0; j < numChks; j++) {
            int ind1 = rand()%ARRAY_SIZE;
            int ind2 = rand()%ARRAY_SIZE;
            swap(leftovers[ind1], leftovers[ind2]);
        }

        // Now remove leftover elements from the list
        // Each loop removes a node
        for (int j = 0; j < numChks; j++) {
            list.Remove(leftovers[j]);
            len--;
            numChks--;
            REQUIRE(list.GetLength() == len);
            REQUIRE(list.LoadFactor() == static_cast<double>(len)/(numChks*ARRAY_SIZE));
        }
    }
}
