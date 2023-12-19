#include "LinkedList.h"

namespace pettystl {
    
    template <typename T> 
    LinkedList<T>::LinkedList(T d) {
         data = d;
         next = nullptr;
    }

    template <typename T> 
    LinkedList<T> * LinkedList<T>::insertData(T d) {
         LinkedList<T> * np = new LinkedList<T>(d);
         np->next = next;
         next = np;
         return np;
    }
    
}