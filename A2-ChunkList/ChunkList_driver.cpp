/**
 * Created by Varick Erickson on 2/9/2021.
 *
 * This file is not graded.  This is a good place to start before using
 * the provided test functions. It shows examples of all the available
 * in ChunkList.  Feel free to modify this file and use it for debugging.
 *
 */

#include "ChunkList.h"

int main(){

    ChunkList<int> chkList;

    cout << "Adding the values: ";
    // Add some numbers
    for (int i = 0; i < 10; i++) {
        chkList.Append(i);
        cout << i << ", ";
    }
    for (int i = 0; i < 10; i++) {
        chkList.Append(-i);
        cout << -i << ", ";
    }
    cout << endl << endl;

    cout << "Checking each index:" << endl;
    for (int i = 0; i < chkList.GetLength(); i++) {
        cout << "chkList index " << i << " has " << chkList.GetIndex(i) << endl;
    }

    cout << endl;

    if (chkList.Contains(0)) {
        cout << "chkList contains 0" << endl;
    } else {
        cout << "chkList does NOT contains 0" << endl;
    }

    if (chkList.Contains(1000)) {
        cout << "chkList contains 1000" << endl;
    } else {
        cout << "chkList does NOT contain 1000" << endl;
    }

    cout << "Removing 9 from list" << endl;
    chkList.Remove(9);

    if (chkList.Contains(9)) {
        cout << "chkList contains 9" << endl;
    } else {
        cout << "chkList does NOT contain 9" << endl;
    }
    cout << endl;

    // Create an array with some data
    int data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = 2*i;
    }

    // Use the array with the constructor
    ChunkList<int> chkList2(data, 100);
    cout << "Checking list using iterator:" << endl;
    chkList2.ResetIterator();
    for (int i = 0; i < chkList2.GetLength(); i++) {
        cout << chkList2.GetNextItem() << ", ";
    }
    cout << endl;

    // Example of a throw
    try {
        ChunkList<int> chkList3(data, -100);
    }
    catch (InvalidArrayLength error) {
        cout << error.Msg() << endl;
    }
    return 0;
}