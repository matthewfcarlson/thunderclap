struct Sub {
    int x;
    void f();
};
struct Obj {
    char pad[0x28];
    Sub a;
    char p2[4];
    Sub b;
    char p3[4];
    Sub c;
    char p4[4];
    Sub d;
    void FUN_002900f0();
};
void Obj::FUN_002900f0() {
    d.f();
    c.f();
    b.f();
    a.f();
}