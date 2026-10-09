unsigned __int64 MulDiv64(unsigned __int64 a, unsigned __int64 b, unsigned __int64 c) {
    unsigned __int64 q = a / c;
    unsigned __int64 r = a % c;
    return r * b / c + q * b;
}
