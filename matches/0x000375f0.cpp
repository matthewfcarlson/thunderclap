extern "C" char __cdecl nearFloat(float, float, float);
struct Box {
    float x, y, z, w;
    int Test(Box*, float);
};
static float absbits(float v) {
    union U {
        float f;
        unsigned long i;
    } u;
    u.f = v;
    u.i &= 0x7fffffffUL;
    return u.f;
}
int Box::Test(Box* other, float tolerance) {
    if (!(absbits(x - other->x) <= tolerance)) {
    } else if (!(absbits(y - other->y) <= tolerance)) {
    } else if (!(absbits(z - other->z) <= tolerance)) {
    } else {
        if (nearFloat(w, other->w, tolerance))
            return 1;
    }
    return 0;
}