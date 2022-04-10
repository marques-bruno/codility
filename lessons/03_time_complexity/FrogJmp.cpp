int solution(int X, int Y, int D) {
    int L = Y - X;
    // Careful, cast to float does not pass all tests...
    if (double(L)/D != L/D) {
        return L/D+1;
    }
    return L/D;
}
