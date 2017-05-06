
#include <cmath>
#include <cassert>

#ifndef utility_h
#define utility_h

//returns p^q in less than O(q)
long powerOf(int p, int q){
    long result = 1;
    while(q > 0){
        if(q & 1)
            result *= p;
        p *= p;
        q >>= 1;
    }
    return result;
}

long powRecursive(int p, int q){
    if(!q) return 1;
    return p * powRecursive(p,q-1);
}

int charToDigit(char a){
    if(a >= '0' && a <= '9') return a - '0';
    else if(a >= 'A' && a <= 'F') return 10 + a - 'A';
    else if(a >= 'a' && a <= 'f') return 10 + a - 'a';
    return -1;
}

int convertToBase(int base, std::string num){
    assert(base > 1);
    int result = 0;
    for(int i = (int)num.length() - 1 ; i >= 0; --i){
        int val = charToDigit(num[i]);
        result += powerOf(base,(int)num.length() - 1 - i) * val;
    }
    return result;
}

bool binaryEqualsHex(std::string binary, std::string hexidecimal){
    int bin = convertToBase(2,binary);
    int hex = convertToBase(16,hexidecimal.substr(2,hexidecimal.length() - 1));
    return bin == hex;
}

long mult(int p, int q){
    int sign = 1;
    if(p < 0 ^ q < 0){
        if(p < 0) p *= -1;
        else q *= -1;
        sign = -1;
    }
    int result = 0,place = 0;
    while(q > 0){
        if(q & 1){
            result += p * (1 << place);
        }
        place++;
        q >>= 1;
    }
    return result * sign;
}

inline int getBit(int number, int place){
    return ((number & (1 << place)) >> place);
}

long add(int p, int q){
    int len = ceil(p > q ? log2(p) : log2(q)) + 1;
    long sum = 0;
    int carry = 0;
    for(int i = 0; i <= len; ++i){
        int bitSum = getBit(p,i) + getBit(q,i) + carry;
        carry = 0;
        if(bitSum == 3){
            bitSum = 1;
            carry = 1;
        }
        if(bitSum == 2){
            bitSum = 0;
            carry = 1;
        }
        sum += bitSum << i;
    }
    return sum;
}

long sub(int p, int q){
    while (q != 0){
        int borrow = (~p) & q;
        p ^= q;
        q = borrow << 1;
    }
    return p;
}

#endif /* utility_h */
