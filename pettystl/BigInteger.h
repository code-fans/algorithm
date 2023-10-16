#include <iostream>

#define BIG_INTEGET_MAX_LENGTH 1000
namespace pettystl {
    typedef unsigned char byte;
    class BigInteger {
        private:
            byte data[BIG_INTEGET_MAX_LENGTH];
            int len;
            int sign;
        private:
            void trimHighZero();
            int absCompare(const byte * bint1, int bint1L, const byte * bint2, int bint2L) const;
            int absAdd(byte dest[], const BigInteger& bint1, const BigInteger& bint2, int powerOffset = 0);
            int absMinus(byte dest[], const BigInteger& bint1, const BigInteger& bint2) const;
            int absMinus(byte dest[], int len, const BigInteger& bint2) const;
            int absMultiplyOneDigit(byte dest[], const BigInteger& other, const byte digit);
            int absDivideOneStep(byte dest[], int len, const BigInteger& other);
        public:
            BigInteger();
            ~BigInteger();
            std::string toString() const;
            BigInteger& fromString(const std::string str);
            bool isZero() const;
            int compareTo(const BigInteger& other) const;

            friend bool operator == (const BigInteger& other, const BigInteger& other2);
            friend bool operator != (const BigInteger& other, const BigInteger& other2);
            friend bool operator >= (const BigInteger& other, const BigInteger& other2);
            friend bool operator > (const BigInteger& other, const BigInteger& other2);
            friend bool operator <= (const BigInteger& other, const BigInteger& other2);
            friend bool operator < (const BigInteger& other, const BigInteger& other2);

            friend std::ostream& operator << (std::ostream& os, const BigInteger& other);
            friend std::istream& operator >> (std::istream& is, BigInteger& other);

            friend BigInteger operator+ (const BigInteger& other, const BigInteger& other2);
            friend BigInteger operator- (const BigInteger& other, const BigInteger& other2);
            friend BigInteger operator* (const BigInteger& other, const BigInteger& other2);
            friend BigInteger operator/ (const BigInteger& other, const BigInteger& other2);
            friend BigInteger operator% (const BigInteger& other, const BigInteger& other2);
    };
}
