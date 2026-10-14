struct Vec3 {
    int x;
    int y;
    int z;
};
struct Obj {
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(const Vec3* v);
};
bool Obj::Set(const Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
