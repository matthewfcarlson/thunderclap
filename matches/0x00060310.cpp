struct V3 {
    int x, y, z;
};
struct Obj {
    char pad[0x84];
    int a;
    int b;
    int c;
    bool Set(const V3* v);
};
bool Obj::Set(const V3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
