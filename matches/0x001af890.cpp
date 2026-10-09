struct V {
    float x, y, z;
};
struct M {
    char pad[8];
    V* items;
};
struct S {
    void Xf(V* src, V* dst);
};
struct T {
    char p0[0x44];
    M* mgr;
    char p1[4];
    S sub;
    char p2[0x7f];
    char flag;
    V Get(unsigned short i);
};
V T::Get(unsigned short i) {
    if (flag) {
        V t;
        sub.Xf(&mgr->items[i], &t);
        return t;
    }
    return mgr->items[i];
}