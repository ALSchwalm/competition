#include <vector>

using std::vector;

/*
 Copyright (c) 2008 Florian Mayer

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
*/
vector<unsigned long> find_primes(unsigned long max) {
    vector<unsigned long> primes;
    vector<char> sieve(max/8+1, 0xFF);
    for(unsigned long x = 2; x <= max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))) {
            primes.push_back(x);
            // Is prime. Mark multiplicates.
            for(unsigned long j = 2*x; j <= max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    return primes;
}
