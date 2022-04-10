#include <vector>
#include <iostream>

using namespace std;

vector<int> get_sums(vector<int> &A) {
    vector<int> sums(A.size());
    int west_counter = 0;
    for (int i = A.size()-1 ; i >= 0 ; i--) {
        if (A[i])
            ++west_counter;
        else
            sums[i] = west_counter;
    }
    return sums;
}

int get_pairs(vector<int>& A, vector<int>& sums) {
    size_t pairs = 0;
    for (size_t i = 0 ; i < A.size() ; ++i)
        if (!A[i])
            pairs += sums[i];
    if (pairs > 1000000000)
        return -1;
    return int(pairs);
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sums = get_sums(A);
    return get_pairs(A, sums);
}

int main(int ac, char**av) {
  vector<int> A = {0,1,0,1,1};
    cout << solution(A) << endl;
}
