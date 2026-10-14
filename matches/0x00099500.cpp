struct Inner_99500 {
    char p0[0x174];
    int a174;
    char p1[0x1ac - 0x178];
    int a1ac;
    char p2[0x1e4 - 0x1b0];
    int a1e4;
    char p3[0x21c - 0x1e8];
    int a21c;
    char p4[0x288 - 0x220];
    int a288;
    int a28c;
    int a290;
};
class C_99500 {
  public:
    void f(int a, int b, int c, int d, int e, int g);
    char p[0xc4];
    Inner_99500* m;
};
void C_99500::f(int a, int b, int c, int d, int e, int g) {
    m->a1e4 = a;
    m->a1ac = b;
    Inner_99500* i = m;
    i->a288 = c;
    i->a28c = d;
    i->a290 = e;
    i->a21c = 0;
    m->a174 = g;
}