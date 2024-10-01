//
// Your code here
//

#include "ChunkList.h"



template <class T>
inline ChunkList<T>::ChunkList()
{
    head = nullptr
    tail = nullptr;
    listLen = 0;
    iterNode = nullptr;
    arrPos= 0;
    numChunks= 0;
}

template <class T>
inline ChunkList<T>::ChunkList(T arr[], int arrLen)
{
    head = nullptr
    tail = nullptr;
    listLen = 0;
    numChunks= 0;

}

template <class T>
inline int ChunkList<T>::GetLength()
{
    return listLen;
}

template <class T>
inline double ChunkList<T>::LoadFactor()
{
    if(head == nullptr){
        throw EmptyList();
    }
    
}

template <class T>
inline int ChunkList<T>::ResetIterator()
{
   arrPos = 0;
    iterNode = nullptr;
}
