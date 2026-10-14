struct Src {
    int a;
    int b;
    int c;
};
struct Obj {
    char pad[0x24];
    int m24, m28, m2c;
    bool Set(Src* p);
};
bool Obj::Set(Src* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}
