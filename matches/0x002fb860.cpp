struct Vec {
    float x, y, z;
};
struct Obj {
    char pad[0x38];
    int mode;
    char pad2[12];
    float sx, sy, sz;
    Vec a, b, c;
    void FUN_002fb860(Vec* out, int index);
};
void Obj::FUN_002fb860(Vec* out, int index) {
    float sign = index > 3 ? -1.0f : 1.0f;
    float x = sign * sx;
    float y = sign * sy;
    float z = sign * sz;
    if (index % 4 > 1)
        y = y * -1.0f;
    if (index % 2 == 1)
        z = z * -1.0f;
    if (!mode) {
        out->x = (z * c.x + y * b.x) + x * a.x;
        out->y = (z * c.y + y * b.y) + x * a.y;
        out->z = (z * c.z + y * b.z) + x * a.z;
    } else {
        out->x = x * a.x;
        out->y = y * b.y;
        out->z = z * c.z;
    }
}
