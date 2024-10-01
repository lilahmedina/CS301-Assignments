/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * You should not remove or change any of the tests in this file.
 * These are the same tests that will be used to grade your assignment.
 * If you want to run your own tests, it is recommended you use the provided
 * my_tests.cpp file.
 *
 * Provides utility functions for the tests. DO NOT MODIFY!
 */

#ifndef UNIT_UTILS_H
#define UNIT_UTILS_H

#include <fstream>

void init_arr(string filename, int data[], int& len) {

    ifstream datafile;
    datafile.open(filename);
    if (datafile.fail()){
        INFO("File did not open.  Did you set your working directory?");
        FAIL();
    }
    int i = 0;
    while (datafile >> data[i++]);
    len = i - 1;
}


// Slide elements over to remove value
void remove_value(int value, int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (value == arr[i]) {
            // slide stuff over
            for (int j = i; i < len-1; i++) {
                arr[i] = arr[i+1];
            }
            return;
        }
    }
}

#endif //UNIT_UTILS_H
