typedef unsigned char u8;
__int64 Make(int);
void __stdcall Init(int, int, int);
class Obj {
  public:
    char pad[0xC];
    volatile int value;
    char rest[0xA0];
    unsigned int a;
    unsigned int b;
    volatile u8 c;
    Obj* Build(int, int, int, u8);
};
Obj* Obj::Build(int p2, int p3, int p4, u8 p5) {
    Init(1, 0xc0, p2);
    union U {
        __int64 q;
        struct {
            unsigned int lo, hi;
        } s;
    } u;
    u.q = Make(p3);
    a = u.s.lo;
    b = u.s.hi;
    c = p5;
    value = p4;
    return this;
}