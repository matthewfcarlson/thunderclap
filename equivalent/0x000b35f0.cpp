// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b35f0 @ 0x000b35f0
struct Entry3 {
    int a, b, c;
};
struct Entry14 {
    int w[14];
};
struct Table_b35f0 {
    Entry3 small[13];
    Entry14 big[2];
};
void __stdcall FUN_000b35f0(Table_b35f0* t, bool clearBig) {
    for (int i = 0; i < 13; i++) {
        t->small[i].a = 0;
        t->small[i].b = 0;
        t->small[i].c = 0;
    }
    if (clearBig) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 14; j++)
                t->big[i].w[j] = 0;
    }
}
