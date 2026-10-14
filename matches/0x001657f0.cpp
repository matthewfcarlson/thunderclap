struct Src_1657f0 {
    int a;
    int b;
    int c;
};
struct Obj_1657f0 {
    char pad[0x18];
    int x;
    int y;
    int z;
    bool Set(Src_1657f0* s);
};
bool Obj_1657f0::Set(Src_1657f0* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}