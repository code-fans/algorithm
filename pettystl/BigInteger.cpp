
#include <cstdio>
#include "BigInteger.h"

namespace pettystl {
    
    BigInteger::BigInteger() {
        sign = 1;
        len=1;
        //data = {0};
    }

    BigInteger::~BigInteger() {

    }

    void BigInteger::trimHighZero() {
        while(len>1 && data[len-1] == 0){
            len --;
        }
    }

    int BigInteger::absCompare(const byte * bint1, int bint1L, const byte * bint2, int bint2L) const{
        if(bint1L>bint2L)
            return 1;
        if(bint1L<bint2L)
            return -1;
        for(int i= bint1L-1; i>=0; i--) {
            if(bint1[i] > bint2[i])
                return 1;
            if(bint1[i] < bint2[i])
                return -1;
        }
        return 0;
    }

    int BigInteger::absAdd(byte dest[], const BigInteger& other, const BigInteger& other2, int powerOffset) {
        int z = 0;
        int len = std::max(other.len, other2.len + powerOffset);
        for (int i = 0; i< len; i++) {
            int a=0, b=0;
            if(i<other.len)
                a= other.data[i];

            if(i>=powerOffset && i<other2.len+powerOffset)
                b=other2.data[i-powerOffset];

            dest[i] = (a+b+z)%10;
            z=(a+b+z)/10;
        }
        if (z!=0) {
            dest[len] = z;
            len ++;
        }
        dest[len] = 0;
        return len;
    }

    int BigInteger::absMinus(byte dest[], const BigInteger& other, const BigInteger& other2) const {
        int z = 0;
        int len = other.len; // bint1 >= bint2
        for (int i = 0; i< len; i++) {
            int a=0, b=0;
            if(i<other.len)
                a= other.data[i];

            if(i<other2.len)
                b=other2.data[i];

            if(a+z<b){
                dest[i] = (10+a+z -b);
                z = -1;
            } else {
                dest[i] = (a+z - b); 
                z = 0;
            }
        }
        dest[len] = 0;
        return len;
    }

    int BigInteger::absMinus(byte dest[], int len, const BigInteger& other2) const{
        int z = 0;
        for (int i = 0; i< len; i++) {
            int a=0, b=0;
            if(i<len)
                a= dest[i];

            if(i<other2.len)
                b= other2.data[i];

            if(a+z<b){
                dest[i] = (10+a+z -b);
                z = -1;
            } else {
                dest[i] = (a+z - b); 
                z = 0;
            }
        }
        dest[len] = 0;
        return len;
    }

    std::string BigInteger::toString() const {
        char str[BIG_INTEGET_MAX_LENGTH];
        int pos=0;
        if(sign<0){
            str[pos++] = '-';
        }
        for(int i=len-1; i>=0; i--){
            str[pos++] = data[i]+'0';
        }
        str[pos++]='\0';
        std::string s = str;
        return s;
    } 

    BigInteger& BigInteger::fromString(const std::string str) {
        len = str.length();
        sign = 1;
        int bPos = 0;
        if(str[0] == '+' || str[0] == '-'){
            sign =str[0] == '-' ? -1 : 1;
            len -- ;
            bPos = 1;
        }
        int n=0;
        for(int i= str.length()-1; i>=bPos; i--){
            data[n++] = str[i] - '0';
        }
        data[len] = 0;
        trimHighZero();
        return *this;
    }

    bool BigInteger::isZero() const{
        return len == 1 && data[0] == 0;
    }

    int BigInteger::compareTo(const BigInteger& other) const {
        if(this->isZero() && other.isZero())
            return 0;
        if(this->sign > other.sign)
            return 1;
        if(this->sign < other.sign)
            return -1;

        return this->sign * absCompare(this->data, this->len, other.data, other.len);
    }

    bool operator == (const BigInteger& other, const BigInteger& other2) {
        if(other.isZero() && other2.isZero())
            return true;
        if(other.sign != other2.sign || other.len != other2.len)
            return false;
        for(int i=0; i<other.len; i++){
            if(other.data[i] != other2.data[i])
                return false;
        }
        return true;
    }

    bool operator != (const BigInteger& other, const BigInteger& other2){
        return !(other==other2);
    }
    
    bool operator >= (const BigInteger& other, const BigInteger& other2){
        return other.compareTo(other2) >=0;
    }

    bool operator > (const BigInteger& other, const BigInteger& other2){
        return other.compareTo(other2) >0;
    }

    bool operator <= (const BigInteger& other, const BigInteger& other2){
        return other.compareTo(other2) <=0;
    }

    bool operator < (const BigInteger& other, const BigInteger& other2){
        return other.compareTo(other2) <0;
    }

    std::ostream& operator << (std::ostream& os, const BigInteger& other) {
        if(other.sign<0){
            os << '-';
        }
        for(int i=other.len-1; i>=0; i--){
            os << other.data[i];
        }
        return os;
    }

    std::istream& operator >> (std::istream& is, BigInteger& other) {
        std::string str;
        is >> str;
        other.fromString(str);
        return is;
    }

    BigInteger operator+ (const BigInteger& other, const BigInteger& other2) {
        BigInteger sum;
        if(other.sign == other2.sign){
            sum.sign = other.sign;
            sum.len = sum.absAdd(sum.data, other, other2);
            return sum;
        }
        int c = sum.absCompare(other.data, other.len, other2.data, other2.len);
        if(c==0){ // return zero
            return sum;
        }
        if(c>0){
            sum.sign = other.sign;
            sum.len = sum.absMinus(sum.data, other, other2);
            sum.trimHighZero();
            return sum;
        }
        sum.sign = other2.sign;
        sum.len = sum.absMinus(sum.data, other2, other);
        sum.trimHighZero();
        return sum;
    }

    BigInteger operator- (const BigInteger& other, const BigInteger& other2) {
        BigInteger sum;
        if((other.sign>0 && other2.sign<0) || (other.sign<0 && other2.sign>0)){
            sum.sign = other.sign;
            sum.len = sum.absAdd(sum.data, other, other2);
            return sum;
        }

        int c = sum.absCompare(other.data, other.len, other2.data, other2.len);
        if(c==0){ // return zero
             return sum;
        }

        if(c>0){
            sum.sign = other.sign;
            sum.len = sum.absMinus(sum.data, other, other2);
            sum.trimHighZero();
            return sum;
        }

        sum.sign = -1 * other.sign;
        sum.len = sum.absMinus(sum.data, other2, other);
        sum.trimHighZero();
        return sum;
    }

    int BigInteger::absMultiplyOneDigit(byte dest[], const BigInteger& other, const byte digit) {
        int z = 0, shang;
        int b= digit; //1~9
        int len = other.len;
        for (int i = 0; i< len; i++) {
            int a = other.data[i];
            shang = a * b + z;
            dest[i] = shang % 10;
            z= shang/10;
        }
        if (z!=0) {
            dest[len] = z ;
            len ++;
        }
        dest[len] = 0;
        return len;
    }

    BigInteger operator* (const BigInteger& other, const BigInteger& other2) {
        BigInteger mulitply;
        if(other.isZero() || other2.isZero())
            return mulitply;
        BigInteger temp;
        for(int i=0; i<other2.len; i++){
            temp.len = temp.absMultiplyOneDigit(temp.data, other, other2.data[i]);
            mulitply.len = mulitply.absAdd(mulitply.data, mulitply, temp, i);
        }
        mulitply.sign = other.sign * other2.sign;
        return mulitply;
    }

    int BigInteger::absDivideOneStep(byte dest[], int len, const BigInteger& other) {
        int result = 0;
        while(other.absCompare(dest, len, other.data, other.len)>=0){
            other.absMinus(dest, len, other);
            if(dest[len-1]==0)
                len--;
            result++;
        }
        return result;
    }

    BigInteger operator/ (const BigInteger& other, const BigInteger& other2){
        BigInteger divRes;
        divRes.sign = other.sign * other2.sign;
        int resLen = other.len - other2.len + 1;
        if(resLen<1)
            return divRes;

        byte data[BIG_INTEGET_MAX_LENGTH];
        std::memcpy(data, other.data, BIG_INTEGET_MAX_LENGTH);
        
        for(int i=resLen-1; i>=0; i--){
            int dataLen = other2.len;
            if(data[i+other2.len]>0){
                dataLen ++;
            }
            int d = divRes.absDivideOneStep(data + i, dataLen, other2);
            divRes.data[i] = d;
        }
        divRes.len = resLen;
        divRes.data[resLen] = 0;
        divRes.trimHighZero();
        return divRes;
    }
    
    BigInteger operator% (const BigInteger& other, const BigInteger& other2){
        BigInteger remainder;
        remainder.sign = other.sign;
        remainder.len = other.len;
        std::memcpy(remainder.data, other.data, BIG_INTEGET_MAX_LENGTH);
        int resLen = other.len - other2.len + 1;
        if(resLen<1)
            return remainder;

        for(int i=resLen-1; i>=0; i--){
            int dataLen = other2.len;
            if(remainder.data[i+other2.len]>0){
                dataLen ++;
            }
            remainder.absDivideOneStep(remainder.data + i, dataLen, other2);
        }
        remainder.trimHighZero();
        return remainder;
    }
}
