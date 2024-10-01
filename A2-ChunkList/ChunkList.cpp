//
// Your code here
//

#include "ChunkList.h"



template <class T>
ChunkList<T>::ChunkList() // not returning anything so no need to put void
{
    head = nullptr
    tail = nullptr;
    listLen = 0;
    iterNode = nullptr;
    arrPos= 0;
    numChunks= 0;
}

template <class T>
ChunkList<T>::ChunkList(T arr[], int arrLen)
{
    head = nullptr
    tail = nullptr;
    listLen = 0;
    numChunks= 0;

}

template <class T>
void ChunkList<T>::GetLength()
{
    return listLen;
}

template <class T>
void ChunkList<T>::LoadFactor()
{
    if(head == nullptr){
        throw EmptyList();
    }
    
}

template <class T>
void ChunkList<T>::ResetIterator()
{
   arrPos = 0;
    iterNode = nullptr;
}

template <class T>
void ChunkList<T>::Remove(T value){
   if(isEmpty){
       throw EmptyList();
    } else {
        for(int i = 0; i < listLen; i++){
            if(arr[i] == value){
                arr[i] = arr[i+1];
            }
        }
    listLen--; 
   }
}

void ChunkList<T>::ResetIterator()
{
   arrPos = 0;
    iterNode = nullptr;
}




