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
             tokenize<int>(input())
 * Adapted from http://goo.gl/RBt6qS
 */
template<typename T>
vector<T> tokenize(string& in, string delimiters = " \t\n")
{
    const int len = in.length();
    int i = 0;
    vector<T> c;

    while (i < len) {
        i = in.find_first_not_of(delimiters, i);
        int j = in.find_first_of(delimiters, i);
        if(j == -1) {
            c.push_back(convertTo<T>(in.substr(i)));
            break;
        }
        c.push_back(convertTo<T>(in.substr(i, j-i)));
        i = j + 1;
    }
    return c;
}
