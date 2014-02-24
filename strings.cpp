#include "utils.cpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename U>
T convertTo(U& from)
{
    T t;
    stringstream s;
    s << from;
    s >> t;
    return t;
}

/**
 * Break a string into a vector tokens
 *
 * Ex usage: tokenize<int>("12 32 43 19") or
 *           tokenize<int>(input())
 */

template<typename T>
vector<T> tokenize(string in, string delimiters = " \t\n")
{
    foreach(delim, delimiters)
        replace(in.begin(), in.end(), *delim, ' ');

    stringstream s(in);
    T token;
    vector<T> tokens;
    while(s >> token) {
        tokens.push_back(token);
    }

    return tokens;
}
