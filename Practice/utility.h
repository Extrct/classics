
#include <cmath>

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

long mult(int p, int q){
    return 0;
}

long add(int p, int q){
    int len = ceil(p > q ? log2(p) : log2(q));
    long sum = 0;
    int carry = 0;
    for(int i = 0; i < len; ++i){
        int bitSum = p & (1 << i) + q & (1 << i);
        if(bitSum == 2){
            if(carry == 0){
                bitSum = 0;
                carry = 1;
            }else{
                bitSum = 1;
                carry = 1;
            }
        }
        else if(bitSum == 1 && carry == 1) bitSum = 0;
        sum += (bitSum + carry) << i;
    }
    return sum;
}

long sub(int p, int q){
    return p ^ q;
}

#endif /* utility_h */
