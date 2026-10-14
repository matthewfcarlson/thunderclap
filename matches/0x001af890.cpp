struct V {
    float x, y, z;
};
struct M_1af890 {
    char pad[8];
    V* items;
};
struct S_1af890 {
    void Xf(V* src, V* dst);
};
struct T_1af890 {
    char p0[0x44];
    M_1af890* mgr;
    char p1[4];
    S_1af890 sub;
    char p2[0x7f];
    char flag;
    V Get(unsigned short i);
};
V T_1af890::Get(unsigned short i) {
    if (flag) {
        V t;
        sub.Xf(&mgr->items[i], &t);
        return t;
    }
    return mgr->items[i];
}