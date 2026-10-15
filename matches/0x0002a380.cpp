struct Vec {
    float x, y, z;
};
extern "C" double __cdecl sqrt(double);
float __cdecl FUN_0002a380(const Vec* a, const Vec* b) {
    float x = a->x - b->x;
    float y = a->y - b->y;
    float z = a->z - b->z;
    return (float)sqrt(y * y + (x * x + z * z));
}