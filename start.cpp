#include "pettystl/pettystl.h"

#include <array>

int main() {
    pettystl::LinkedList<int> * intList = new pettystl::LinkedList<int>(1);
    pettystl::LinkedList<int> * tmpList = intList;
    for(int i = 2; i<10; i++){
        tmpList = tmpList->insertData(i);
    }
    tmpList = intList;
    while(tmpList != nullptr){
        std::cout << tmpList->data << " ";
    }
    std::cout <<std::endl;
    /*
    pettystl::BigInteger bint1, bint2, bint3;
    std::cin >> bint1 >> bint2;
    bint3 = bint1 * bint2;
    std::cout << bint3 << std::endl;
    */
    return 0;
}
