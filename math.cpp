#include<cmath>

#include "utils.cpp"

//Get primes up to but not including len
vector<unsigned int> primes(unsigned int len) {
    vector<char> primes(len, true);
    
    for(size_t i=3; i < sqrt(len)+1; i+=2) {
        if (primes[i]) {
            for(size_t j=i*i; j < len; j+=i) {
                primes[j] = false;
            }
        }
    }

    vector<unsigned int> out;
    out.push_back(2);
    for(size_t i=3; i < len; i+=2) {
        if (primes[i])
            out.push_back(i);
    }

    return out;
}

/**
 * Call 'u' with every permutation of 't'
 *
 * Ex usage: foreach_permutation(string("cat"), print_one<string>)
 * prints:
 *  act, atc, cat, cta, tac, tca
 */
template<typename T, typename U>
void foreach_permutation(T t, U u) {
    sort(range(t));
    do {
        u(t);
    } while (next_permutation(range(t)));
}   
