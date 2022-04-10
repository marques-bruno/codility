

// you can use includes, for example:
#include <unordered_map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void fill(int& cell, int& dist_counter, char letter, char match) {
    if (letter == match) {
        dist_counter = 0;
    } else if (dist_counter != -1) {
        dist_counter++;
    }
    cell = dist_counter;
}

int find_min_IF(int x, int y, 
    const std::vector<int>& Al, const std::vector<int>& Ar,
    const std::vector<int>& Cl, const std::vector<int>& Cr,
    const std::vector<int>& Gl, const std::vector<int>& Gr,
    const std::vector<int>& Tl, const std::vector<int>& Tr, int min_val)
{
    int max_dist = y - x;
    if ((Al[y] <= max_dist && Al[y] != -1) || (Ar[x] <= max_dist && Ar[x] != -1))
        return 1;
    else if ((Cl[y] <= max_dist && Cl[y] != -1) || (Cr[x] <= max_dist && Cr[x] != -1))
        return 2;
    else if ((Gl[y] <= max_dist && Gl[y] != -1) || (Gr[x] <= max_dist && Gr[x] != -1))
        return 3;
    else if ((Tl[y] <= max_dist && Tl[y] != -1) || (Tr[x] <= max_dist && Tr[x] != -1))
        return 4;
    else
        return 4;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    static const unordered_map<char, int> n = {
        {'A', 1},
        {'C', 2},
        {'G', 3},
        {'T', 4}
    };
    int M = P.size();
    vector<int> Al, Ar, Cl, Cr, Gl, Gr, Tl, Tr;
    Al = Ar = Cl = Cr = Gl = Gr = Tl = Tr = vector<int>(S.size());

    int min_val = 4;
    int Adist = -1;
    int Cdist = -1;
    int Gdist = -1;
    int Tdist = -1;

    int distA = -1;
    int distC = -1;
    int distG = -1;
    int distT = -1;

    auto j = S.size();
    for (auto i = 0 ; i < int(S.size()) ; ++i) {
        j--;
        if (n.at(S[i]) < min_val)
            min_val = n.at(S[i]);
        fill(Al[i], Adist, S[i], 'A');
        fill(Cl[i], Cdist, S[i], 'C');
        fill(Gl[i], Gdist, S[i], 'G');
        fill(Tl[i], Tdist, S[i], 'T');

        fill(Ar[j], distA, S[j], 'A');
        fill(Cr[j], distC, S[j], 'C');
        fill(Gr[j], distG, S[j], 'G');
        fill(Tr[i], distT, S[i], 'T');
    }
    vector<int> results(M, 0);
    
    for (int i = 0 ; i < M ; ++i) {
        results[i] = find_min_IF(P[i], Q[i], Al, Ar, Cl, Cr, Gl, Gr, Tl, Tr, min_val);
    }
    return results;
}

