extern "C" char __cdecl FUN_00018960(float, float, float);
struct Box_375f0 {
    float x, y, z, w;
    int Test(Box_375f0*, float);
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
int Box_375f0::Test(Box_375f0* other, float tolerance) {
    if (!(absbits(x - other->x) <= tolerance)) {
    } else if (!(absbits(y - other->y) <= tolerance)) {
    } else if (!(absbits(z - other->z) <= tolerance)) {
    } else {
        if (FUN_00018960(w, other->w, tolerance))
            return 1;
    }
    return 0;
}