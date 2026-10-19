struct Vec3 {
    float x, y, z;
};
struct Obj {
    char pad[0x34];
    float x, y, z;
    unsigned char FUN_0005a180(const Vec3* v);
};
unsigned char Obj::FUN_0005a180(const Vec3* v) {
    float a = v->z * 0.017453292f, b = v->y * 0.017453292f, c = v->x * 0.017453292f;
    x = c;
    y = b;
    z = a;
    return 1;
}