// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int N = A.size();
    int c = 0;
    int idx = -1;
    for (int i = 0 ; i < N ; ++i) {
        if (c == 0) {
            c++;
            idx = i;
        }
        else if (A[i] != A[idx]) {
            c--;
        }
        else {
            c++;
        }
    }
    // Compute index sums
    int sum = 0;
    vector<int> B(N);
    for (int i = 0 ; i < N ; ++i) {
        if (A[i] == A[idx])
            B[i] = ++sum;
        else
            B[i] = sum;
    }

    // get number of equi leaders:
    c = 0;
    for (int i = 0 ; i < N ; ++i) {
        if ((B[i] > (i+1) / 2.0f) && (B[N-1] - B[i] > (N-(i+1)) / 2.0f))
            c++;
    }
    return c;
}
