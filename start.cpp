#include "pettystl/pettystl.h"

int main() {
    pettystl::BigInteger bint1, bint2, bint3;
    std::cin >> bint1 >> bint2;
    bint3 = bint1 % bint2;
    std::cout << bint3 << std::endl;
    return 0;
}
