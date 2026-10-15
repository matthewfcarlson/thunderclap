struct Vec3 {
    int x, y, z;
};
struct Obj {
    char pad[0x8c];
    int a, b, c;
    void Set(Vec3 const* v);
};
void Obj::Set(Vec3 const* v) {
    a = v->x;
    b = v->y;
    c = v->z;
}
