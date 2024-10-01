/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file.
 *
 * This provides two simple test to do a superficial test of the template.
 */

#include "catch.hpp"
#include "../ChunkList.h"
#include "unit_utils.h"

TEST_CASE("Template Tests") {
    SECTION("Test char - 1pt") {
        ChunkList<char> list;
        for (int i = 0; i < 255; i++) {
            list.Append(static_cast<char>(i));
        }
        list.ResetIterator();
        for (int i = 0; i < 255; i++) {
            REQUIRE(list.GetNextItem() == static_cast<char>(i));
        }
    }
    SECTION("Test float - 1pt") {
        ChunkList<float> list;
        for (float i = 0; i < 100; i+=0.1) {
            list.Append(i);
        }
        list.ResetIterator();
        for (float i = 0; i < 100; i+=0.1) {
            REQUIRE(list.GetNextItem() == i);
        }
    }
}