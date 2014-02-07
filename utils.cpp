#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>

using namespace std;

#define range(container) container.begin(), container.end()

//NOTE: only works with gcc
#define foreach(var, c)                                         \
    for(typeof(c.begin()) var=c.begin(); var != c.end(); ++var)

//Returns input up to first occurrence of delim.
//NOTE: removes delim. Subsequent call to input() will not return delim
string input(char delim='\n') {
    string temp;
    getline(cin, temp, delim);
    return temp;
}

template<typename T>
vector<T> tokenize(const string& s){
    istringstream i(s);
    vector<T> tokens;
    T token;

    while(i >> token) {
        tokens.push_back(token);
    }
    
    return tokens;
}

template<typename T, typename U>
void filter(T& c, U item) {
    c.erase(remove(range(c), item), c.end());
}

template<typename T, typename U>
void filter_if(T& c, U item) {
    c.erase(remove_if(range(c), item), c.end());
}

template<typename T>
void print(T t) {
    foreach(item, t) {
        cout << *item << endl;
    }
}
