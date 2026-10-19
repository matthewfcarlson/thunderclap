struct Vec3 {
    float x, y, z;
};
float __cdecl FUN_00025990(const Vec3* a, const Vec3* b) {
    float x = a->x - b->x;
    float y = a->y - b->y;
    float z = a->z - b->z;
    float r = x * x;
    r += z * z;
    r += y * y;
    return r;
}