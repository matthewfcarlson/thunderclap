struct Vec3 {
    int x, y, z;
};

struct Obj {
    char pad[0x10];
    Vec3 v;
    bool Set(const Vec3* other);
};

bool Obj::Set(const Vec3* other) {
    v.x = other->x;
    v.y = other->y;
    v.z = other->z;
    return true;
}
