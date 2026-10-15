struct V {
    int a, b, c, d;
};
V* __cdecl FUN_002e53c0(V* dst, int n, const V* src) {
    while (n) {
        if (dst)
            *dst = *src;
        ++dst;
        --n;
    }
    return dst;
}