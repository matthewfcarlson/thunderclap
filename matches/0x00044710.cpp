struct Vec3 {
    unsigned int x, y, z;
};
struct Entry {
    Vec3 position;
    char pad[0x28 - sizeof(Vec3)];
};
struct Object {
    char pad[0x1c8];
    Entry entries[8];
    Vec3* FUN_00044710(Vec3* out, int index);
};
Vec3* Object::FUN_00044710(Vec3* out, int index) {
    if (index >= 0 && index < 8) {
        *out = entries[index].position;
    } else {
        out->x = 0;
        out->y = 0;
        out->z = 0;
    }
    return out;
}