#include<cmath>

#include "utils.cpp"

//Get primes up to but not including len
vector<unsigned int> primes(unsigned int max) {
    vector<char> primes(max/8+1, ~0);
    vector<unsigned int> out;
    out.push_back(2);

    for(size_t i=3; i < max ; i+=2) {
        if (primes[i/8] & (1 << (i % 8))) {
            out.push_back(i);

            if (i < sqrt(max)+1) {
                for(size_t j=i*i; j < max; j+=i) {
                    primes[j/8] &= ~(1 << (j % 8));
                }
            }
        }
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
