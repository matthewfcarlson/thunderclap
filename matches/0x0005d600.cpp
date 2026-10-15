struct Vec3 {
    float x, y, z;
};
struct Obj {
    char pad[0xcc];
    Vec3 v;
    bool Set(Vec3 const* p);
};

bool Obj::Set(Vec3 const* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
