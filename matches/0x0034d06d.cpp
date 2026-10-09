// cl-flags: /Oy- /O1
extern void* g_ac;
extern void* g_b4;
extern int g_bc, g_c0;
extern char *g_c4, *g_c8;
extern int g_cc, g_d0;
struct Sub {
    char p[0x3c - 0];
};
struct O {
    char pad[0x3c];
    char sub[1];
    O* Init();
    void Base();
    O* Fn(char* a, int b, char* c, int d, int e);
};
O* O::Fn(char* a, int b, char* c, int d, int e) {
    Base();
    ((O*)sub)->Base();
    g_c0 = b;
    g_bc = b;
    if (a) {
        g_c8 = c - 1;
        g_c4 = a;
    } else {
        g_c4 = 0;
        g_c8 = 0;
    }
    g_cc = e;
    g_b4 = sub;
    g_d0 = d;
    g_ac = this;
    return this;
}
