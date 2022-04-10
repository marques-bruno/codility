int solution(vector<int> &A) {\
    int N = A.size();
    if (N == 0)
        return 1;
    vector<bool> c(N+1, false);

    for (int i = 0 ; i < N ; ++i)
        c[A[i]] = true;
    
    for (int i = 1 ; i <= N ; ++i)
        if (!c[i])
            return i;
    return N+1;
}

