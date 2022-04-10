int solution(string &S) {
    int c = 0;
    for (auto i : S)
    {
        if (i == '(') {
            c++;
        }
        if (i == ')')
        {
            if (--c < 0)
            {
                return 0;
            }
        }
    }
    if (c == 0)
        return 1;
    return 0;
}
