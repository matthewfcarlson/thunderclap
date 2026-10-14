// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002f0080 @ 0x002f0080
struct V3_2f0080 { float x; float y; float z; };
char __cdecl FUN_002f0030(float a, float b, float c);

// Interval overlap test on three axes: true when the extent test on x passes
// outright, otherwise falls back to the z and y interval tests.
bool __cdecl FUN_002f0080(const V3_2f0080* a, const V3_2f0080* b, const V3_2f0080* c)
{
    float m = c->x;
    if (b->x > m && a->x > m)
        return true;
    m = -m;
    if (b->x < m && a->x < m)
        return true;
    if (FUN_002f0030(b->z, a->z, c->z))
        return true;
    return FUN_002f0030(b->y, a->y, c->y) != 0;
}
