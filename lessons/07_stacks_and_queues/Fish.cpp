// you can use includes, for example:
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int safe = 0;
    std::stack<int> stack;
    for (size_t i = 0 ; i < A.size() ; ++i)
    {
        if (B[i] == 0) // upstream fish 
        {
            while (!stack.empty()) {
                if (stack.top() < A[i])
                    stack.pop(); // eats fish in stack
                else {
                    break; // gets eaten
                }
            }
            if (stack.empty())
                safe++;
        }
        else
            stack.push(A[i]); // add downstream fish to stack
    }
    while (!stack.empty()) {
        stack.pop();
        safe++;
    }
    return safe;
}

