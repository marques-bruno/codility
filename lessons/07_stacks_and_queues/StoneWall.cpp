// you can use includes, for example:
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {

    std::stack<int> blocks;
    int block_counter = 0;
    for (int i = 0 ; i < H.size() ; ++i)
    {
        while (!blocks.empty() && H[i] < blocks.top()) {
            block_counter++;
            blocks.pop();
        }
        if (blocks.empty()) {
            blocks.push(H[i]);
        }
        if (H[i] > blocks.top())
            blocks.push(H[i]);
    }
    while (!blocks.empty()) {
        block_counter++;
        blocks.pop();
    }
    return block_counter;
}
