#include <iostream>

#define BIG_INTEGET_MAX_LENGTH 1000
namespace pettystl {
    
    class BigInteger {
        private:
            char data[BIG_INTEGET_MAX_LENGTH];
            int len;
            int sign;
        private:
            void trimHighZero();
            int absCompare(const char * bint1, int bint1L, const char * bint2, int bint2L) const;
            int absAdd(char dest[], const BigInteger& bint1, const BigInteger& bint2, int powerOffset = 0);
            int absMinus(char dest[], const BigInteger& bint1, const BigInteger& bint2) const;
            int absMinus(char dest[], int len, const BigInteger& bint2) const;
            int absMultiplyOneDigit(char dest[], const BigInteger& other, const char digit);
            int absDivideOneStep(char dest[], int len, const BigInteger& other);
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
