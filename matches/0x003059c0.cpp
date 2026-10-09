extern "C" double cos(double);
extern "C" double sin(double);
struct Vec {
    float x, y, z;
    float Len();
};
struct Q {
    float x, y, z, w;
};
bool FUN_003059c0(Vec* a, Q* b) {
    Vec v = *a;
    bool r = false;
    float t = v.Len();
    if (t > 0.0001f) {
        t = t * 0.5f;
        b->w = (float)cos(t);
        float s = (float)sin(t);
        b->x = v.x * s;
        b->y = v.y * s;
        b->z = v.z * s;
        r = true;
    }
    return r;
}