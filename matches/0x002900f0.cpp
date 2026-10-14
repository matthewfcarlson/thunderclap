struct Sub_2900f0 {
    int x;
    void f();
};
struct Obj_2900f0 {
    char pad[0x28];
    Sub_2900f0 a;
    char p2[4];
    Sub_2900f0 b;
    char p3[4];
    Sub_2900f0 c;
    char p4[4];
    Sub_2900f0 d;
    void FUN_002900f0();
};
void Obj_2900f0::FUN_002900f0() {
    d.f();
    c.f();
    b.f();
    a.f();
}