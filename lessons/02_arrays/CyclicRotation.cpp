#include <vector>

vector<int> solution(vector<int> &A, int K) {
    int N = A.size();
    if (N < 2)
        return A;
    if (K >= N)
        K -= (K / N * N);
    vector<int> Abis = A;
    int i;
    for (i = 0 ; N - K + i < N ; i++)
        Abis[i] = A[N - K + i];
    for (int j = 0 ; j < N-K ; ++j) {
        Abis[i++] = A[j];
    }
    return Abis;
}
