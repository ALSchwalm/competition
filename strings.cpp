/**
 * Break a string into a vector tokens
 *
 * Ex usage: tokenize<int>("12 32 43 19") or
             tokenize<int>(input())
 */
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
