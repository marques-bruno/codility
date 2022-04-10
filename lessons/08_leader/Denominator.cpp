int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int idx = -1;
    int c = 0;
    for (int i = 0 ; i < N ; ++i) {
        if (c == 0) {
            idx = i;
            c++;
        }
        else if (A[i] != A[idx]) {
            c--;
        }
        else
            c++;
    }
    c = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        if (A[i] == A[idx])
            c++;
    }
    if (c >= N / 2 +1)
        return idx;
    return -1;
}
