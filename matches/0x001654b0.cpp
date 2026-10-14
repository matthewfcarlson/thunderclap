struct Src_1654b0 {
    int a;
    int b;
    int c;
};
struct Obj_1654b0 {
    char pad[0x24];
    int m24, m28, m2c;
    bool Set(Src_1654b0* p);
};
bool Obj_1654b0::Set(Src_1654b0* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}
