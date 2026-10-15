struct Sub {
    char pad[12];
    void Copy(Sub*);
};
struct Elem {
    int x;
    Sub sub;
};
Elem* __cdecl FUN_002a4c60(Elem* dst, int n, Elem* src) {
    if (n != 0) {
        int i = n;
        do {
            if (dst) {
                dst->x = src->x;
                dst->sub.Copy(&src->sub);
            }
            ++dst;
        } while (--i);
    }
    return dst;
}