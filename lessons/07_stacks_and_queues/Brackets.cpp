// you can use includes, for example:
#include <stack>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::string& S) {
    std::stack<int> stack;
    
    char c = '\0';
    for (size_t i =0 ; i < S.length() ; ++i) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{')
            stack.push(S[i]);
        else {
            c = stack.top();
            if (stack.empty())
                return 0;
            if ((S[i] == ')' && c != '(') ||
                (S[i] == ']' && c != '[') ||
                (S[i] == '}' && c != '{'))
                return 0;
            stack.pop();
        }
    }
    if (stack.empty())
        return 1;
    return 0;
}
