struct Table {
    int pad;
    int values[1];
};
extern Table tbl;
struct A {
    int x;
};
extern void __cdecl FUN_002628a0(int, A*, A*);
int __cdecl FUN_00262930(int pos, A* b, A* a) {
    int v = pos - a->x;
    int c = tbl.values[b->x];
    int r;
    if (v < 0) {
        r = 8;
        v = -v;
    } else
        r = 0;
    if (v >= c) {
        r |= 4;
        v -= c;
    }
    c >>= 1;
    if (v >= c) {
        r |= 2;
        v -= c;
    }
    c >>= 1;
    if (v >= c)
        r |= 1;
    FUN_002628a0(r, b, a);
    return r;
}