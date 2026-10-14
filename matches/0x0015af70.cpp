struct Vec3_15af70 {
    int x;
    int y;
    int z;
};
struct Obj_15af70 {
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(const Vec3_15af70* v);
};
bool Obj_15af70::Set(const Vec3_15af70* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
