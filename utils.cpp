#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
#include<cstdlib>

using namespace std;

#define range(container) container.begin(), container.end()

//NOTE: only works with gcc
#define foreach(var, c) \
    for(typeof(c.begin()) var=c.begin(); var != c.end(); ++var)

#define forrange(var, r) \
    for(size_t var=0; var < r; ++var)

//Returns input up to first occurrence of delim.
//NOTE: removes delim. Subsequent call to input() will not return delim
string input(char delim='\n') {
    string temp;
    getline(cin, temp, delim);
    return temp;
}

template<typename T, typename U>
void filter(T& c, const U& item) {
    c.erase(remove(range(c), item), c.end());
}

template<typename T, typename U>
void filter_if(T& c, const U& item) {
    c.erase(remove_if(range(c), item), c.end());
}

template<typename T>
void print_all(const T& t) {
    foreach(item, t) print_one(*item);
}

template<typename T>
void print(const T& t) {cout << t << endl;}
