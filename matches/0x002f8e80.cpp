class Obj_2f8e80 {
  public:
    char pad[0x68];
    unsigned char m68;
    unsigned char m69;
    char p[6];
    unsigned char m70;
};
class Pair_2f8e80 {
  public:
    Obj_2f8e80* a;
    Obj_2f8e80* b;
    int c;
    int d;
    unsigned char e;
    void f();
};
void Pair_2f8e80::f() {
    unsigned char z = 0;
    c = 0;
    if (a->m70 == z || b->m70 == z) {
        e = z;
        return;
    }
    if (a->m69 != z || b->m69 != z) {
        d = 0;
        e = 1;
        return;
    }
    if (a->m68 != z || b->m68 != z) {
        e = 1;
        return;
    }
    e = z;
}
