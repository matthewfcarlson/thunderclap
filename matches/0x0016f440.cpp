struct Vec3 {
    int x, y, z;
};
struct Obj {
    char pad[0x2c];
    int a, b, c;
    bool Set(Vec3* v);
};
bool Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}