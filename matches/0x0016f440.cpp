struct Vec3_16f440 {
    int x, y, z;
};
struct Obj_16f440 {
    char pad[0x2c];
    int a, b, c;
    bool Set(Vec3_16f440* v);
};
bool Obj_16f440::Set(Vec3_16f440* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}