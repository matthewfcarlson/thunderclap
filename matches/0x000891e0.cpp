class Data_891e0;
class Owner_891e0 {
  public:
    char pad[0xac8];
    Data_891e0* p;
    unsigned int Fn();
};
class Data_891e0 {
  public:
    char pad0[4];
    unsigned char a;
    char p0[3];
    unsigned int n0;
    char p1[0xbec - 12];
    unsigned char b;
    char p2[3];
    unsigned int n1;
    char p3[0x17d4 - 0xbf4];
    unsigned char c;
    char p4[3];
    unsigned int n2;
    char p5[0x23bc - 0x17dc];
    unsigned char d;
    char p6[3];
    unsigned int n3;
    char p7[0x2fa4 - 0x23c4];
    unsigned char e;
    char p8[3];
    unsigned int n4;
};
unsigned int Owner_891e0::Fn() {
    Data_891e0* x = p;
    unsigned int m = 0;
    unsigned int r = 0;
    if (x->a && x->n0 > 0)
        m = x->n0;
    if (x->b && x->n1 > m) {
        m = x->n1;
        r = 1;
    }
    if (x->c && x->n2 > m) {
        m = x->n2;
        r = 2;
    }
    if (x->d && x->n3 > m) {
        m = x->n3;
        r = 3;
    }
    if (x->e && x->n4 > m)
        r = 4;
    return r;
}