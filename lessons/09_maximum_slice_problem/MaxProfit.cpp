// you can use includes, for example:
#include <algorithm>


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();

    int last_buy_idx, last_win_idx, fluctuation, max_fluctuation;
    last_buy_idx = last_win_idx = fluctuation = max_fluctuation = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        int current_fluctuation = std::max(A[i] - A[last_win_idx] + fluctuation, 0);
        if (current_fluctuation == 0) {
            last_buy_idx = last_win_idx = i;
            fluctuation = 0;
        }
        else if (current_fluctuation > fluctuation) {
            fluctuation = current_fluctuation;
            last_win_idx = i;
        }
        max_fluctuation = max(max_fluctuation, fluctuation);
    }
    return max_fluctuation;
}
