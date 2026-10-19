typedef unsigned char u8_1c9920;
__int64 Make(int);
struct ThisCall_001c9750 {
    void Init(int, int, int);
};
class Obj_1c9920 {
  public:
    char pad[0xC];
    volatile int value;
    char rest[0xA0];
    unsigned int a;
    unsigned int b;
    volatile u8_1c9920 c;
    Obj_1c9920* Build(int, int, int, u8_1c9920);
};
Obj_1c9920* Obj_1c9920::Build(int p2, int p3, int p4, u8_1c9920 p5) {
    ((ThisCall_001c9750*)(this))->Init(1, 0xc0, p2);
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