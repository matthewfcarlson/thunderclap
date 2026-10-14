struct Vec3_143430 {
    int x, y, z;
};

struct Obj_143430 {
    char pad[0x10];
    Vec3_143430 v;
    bool Set(const Vec3_143430* other);
};

bool Obj_143430::Set(const Vec3_143430* other) {
    v.x = other->x;
    v.y = other->y;
    v.z = other->z;
    return true;
}
