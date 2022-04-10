#include <bitset>

int solution(int N) {
    int max_c = 0;
    int c = 0;
    bool found_one = false;
    for (int i = 0 ; i < 32 ; ++i)
    {
        if (N & 1) {
            max_c = max(max_c,c);
            c = 0;
            found_one = true;
        } else if (found_one) {
            c++;
        }
        // cout << bitset<8>(N).to_string() << " " << (N & 1) << " " << c << endl;
        N = N >> 1;
    }
    return max_c;
}
