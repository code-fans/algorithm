#include <iostream>

namespace pettystl {
    template <typename T> class LinkedList{
        public:
            T data;
            LinkedList<T> * next;
        public:
            LinkedList(T d);
            LinkedList<T> * insertData(T d);
    };

}