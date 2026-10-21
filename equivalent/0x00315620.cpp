// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 12/12)
// FUN_00315620 @ 0x00315620
#include "compat/ptr.h"
struct Vec3_315620 {
    float x, y, z;
    void FUN_00011160(float amount, Vec3_315620* dir);
    float FUN_0022d110();
};

union FloatBits_315620 {
    float f;
    unsigned int u;
};

class Body_315620 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_315620* vfunc_4();
};

class Resolver_315620 {
public:
    char pad0[0x14];
    Vec3_315620 offset;
    void FUN_00314be0(Body_315620* a, Vec3_315620* pa, Body_315620* b, Vec3_315620* pb, float depth, Vec3_315620* dir);
    bool FUN_00315620(Vec3_315620* p0, Vec3_315620* axis0, float k0, Vec3_315620* p1, Vec3_315620* axis1, float k1, Vec3_315620* ref, float scale, float sign, Body_315620* b0, Body_315620* b1);
};

bool Resolver_315620::FUN_00315620(Vec3_315620* p0, Vec3_315620* axis0, float k0, Vec3_315620* p1, Vec3_315620* axis1, float k1, Vec3_315620* ref, float scale, float sign, Body_315620* b0, Body_315620* b1)
{
    Vec3_315620 d;
    FloatBits_315620 bits;

    d.x = (p1->x - p0->x) + offset.x;
    d.y = (p1->y - p0->y) + offset.y;
    volatile float dzr = p1->z - p0->z; // the original rounds the z difference before adding the offset
    d.z = dzr + offset.z;

    hulk_freg cx = d.y * ref->z - d.z * ref->y;
    hulk_freg cy = d.z * ref->x - d.x * ref->z;
    hulk_freg cz = d.x * ref->y - d.y * ref->x;
    hulk_freg inv = 1.0f / (scale * scale);

    double u0 = (cz * axis0->z + cy * axis0->y + cx * axis0->x) * k0; // MSVC would reassociate dot*k0*inv
    float t0 = u0 * inv;
    bits.f = t0;
    bits.u &= 0x7fffffff;
    if (!(bits.f <= 1.0f))
        return false;

    double u1 = (cz * axis1->z + cy * axis1->y + cx * axis1->x) * k1;
    float t1 = u1 * inv;
    bits.f = t1;
    bits.u &= 0x7fffffff;
    if (!(bits.f <= 1.0f))
        return false;

    if (b0 == 0 || b1 == 0)
        return true;

    Vec3_315620* v0 = b0->vfunc_4();
    p0->x = v0->x + p0->x;
    p0->y = v0->y + p0->y;
    p0->z = v0->z + p0->z;
    Vec3_315620* v1 = b1->vfunc_4();
    p1->x = p1->x + v1->x;
    p1->y = v1->y + p1->y;
    p1->z = v1->z + p1->z;

    p0->FUN_00011160(-(t1 * k0), axis0);
    p1->FUN_00011160(-(t0 * k1), axis1);

    d.x = p0->x - p1->x;
    d.y = p0->y - p1->y;
    d.z = p0->z - p1->z;
    float len = d.FUN_0022d110();
    if (len < 1.0e-6f)
        return false;
    if (sign < 0.0f) {
        len = -len;
        d.x = d.x * -1.0f;
        d.y = d.y * -1.0f;
        d.z = d.z * -1.0f;
    }
    FUN_00314be0(b0, p0, b1, p1, len, &d);
    return true;
}
