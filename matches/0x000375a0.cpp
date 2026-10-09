struct V3 {
    float x;
    float y;
    float z;
};
extern const float gOne;
extern const float gEpsilon;
extern "C" bool __fastcall FUN_000375a0(V3* p) {
    union U {
        float f;
        unsigned int i;
    } u;
    u.f = p->z * p->z + p->y * p->y + p->x * p->x - gOne;
    u.i &= 0x7fffffff;
    return u.f <= gEpsilon;
}