struct B {
    unsigned char v;
};
struct Obj {
    void invoke(B, B, B, B, B, unsigned char, int);
};
typedef void (Obj::*CB)(B, B, B, B, B, unsigned char, int);
struct Rec {
    B a;
    char p[3];
};
void f(Obj* obj, Rec* r, int unused2, CB cb) {
    B a = (r++)->a, b = (r++)->a, c = (r++)->a, d = (r++)->a, e = (r++)->a;
    (obj->*cb)(a, b, c, d, e, r->a.v, *(int*)(r + 1));
}