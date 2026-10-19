// STATUS: equivalent (tools/equiv.py level 3: 3041 inputs, branch coverage 30/30)
// FUN_00301e10 @ 0x00301e10
// FUN_00301e10 @ 0x00301e10
#include "decls/data/engine/unknown.h"

extern "C" double sqrt(double);
struct Vec3_301e10 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float s, Vec3_301e10 *dir);
    void FUN_001f6bc0(Vec3_301e10 *base, float s, Vec3_301e10 *dir);
};
union FloatBits_301e10 { float f; unsigned int u; };
struct PtrRange_301e10 { char *begin; char *end; };
class Cap {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3_301e10 *GetPos();
    char pad04[0x10];
    PtrRange_301e10 *list;
    char pad18[0x44 - 0x18];
    Vec3_301e10 dir;
    float radius;
    float half;
};
class Collider_301e10 {
public:
    char pad00[0xc];
    float margin;
    char pad10[4];
    Vec3_301e10 d;
    char FUN_00315620(Vec3_301e10 *out, Vec3_301e10 *axis, float ext, Vec3_301e10 *u, Vec3_301e10 *b, float f50, float *kv, float L, float m, Cap *a, Cap *cap);
    void FUN_00314be0(Cap *a, Vec3_301e10 *p1, Cap *b, Vec3_301e10 *p2, float depth, Vec3_301e10 *dir);
    void FUN_00318bb0(Cap *a, Cap *b);
    void FUN_00318910(Cap *a, Cap *b);
    void FUN_00317700(Cap *a, Cap *b, int x, int y);
    void FUN_00301e10(Cap *a, Cap *b);
};

void Collider_301e10::FUN_00301e10(Cap *a, Cap *b)
{
    Vec3_301e10 k, contactA, contactB, axial, radial;
    float radialGap;
    Vec3_301e10 *posA = a->GetPos();
    Vec3_301e10 *posB = b->GetPos();
    d.x = posB->x - posA->x;
    d.y = posB->y - posA->y;
    d.z = posB->z - posA->z;

    Vec3_301e10 *axisA = &a->dir;
    Vec3_301e10 *axisB = &b->dir;
    double crossX = axisA->y * axisB->z - axisA->z * axisB->y;
    double crossY = axisA->z * axisB->x - axisA->x * axisB->z;
    volatile float crossZ = axisA->x * axisB->y - axisA->y * axisB->x;
    double radii = b->radius * a->radius;
    volatile float roundedRadii = (float)radii;
    k.x = (float)(radii * crossX);
    k.y = (float)(crossY * roundedRadii);
    double kz = crossZ * roundedRadii;
    k.z = (float)kz;
    double squaredLength = kz * k.z + k.y * k.y + k.x * k.x;
    volatile float roundedSquaredLength = (float)squaredLength;
    if (squaredLength > 9.99999997475243e-007f) {
        double projectedDistance = k.z * d.z + k.y * d.y + k.x * d.x;
        FloatBits_301e10 absoluteProjection;
        absoluteProjection.f = (float)projectedDistance;
        absoluteProjection.u &= 0x7fffffff;
        if (absoluteProjection.f > 9.99999997475243e-007f) {
            volatile float length = (float)sqrt((double)roundedSquaredLength);
            double inverseLength = 1.0f / length;
            volatile float roundedInverseLength = (float)inverseLength;
            double signedDistance = inverseLength * projectedDistance;
            double sign = signedDistance < 0.0 ? -1.0f : signedDistance > 0.0 ? 1.0f : 0.0f;
            double scale = sign * roundedInverseLength;
            double scaleA = scale * a->half;
            contactA.x = (float)(k.x * scaleA);
            contactA.y = (float)(k.y * scaleA);
            contactA.z = (float)(k.z * scaleA);
            double scaleB = -(scale * b->half);
            contactB.x = (float)(k.x * scaleB);
            contactB.y = (float)(k.y * scaleB);
            contactB.z = (float)(k.z * scaleB);
            FloatBits_301e10 absoluteDistance;
            absoluteDistance.f = (float)signedDistance;
            absoluteDistance.u &= 0x7fffffff;
            double separation = absoluteDistance.f - a->half - b->half;
            volatile float roundedSeparation = (float)separation;
            if (separation < margin) {
                bool aHasItems = a->list && ((int)(a->list->end - a->list->begin) & ~3) != 0;
                if (!aHasItems) {
                    bool bHasItems = b->list && ((int)(b->list->end - b->list->begin) & ~3) != 0;
                    if (!bHasItems && FUN_00315620(&contactA, axisA, a->radius, &contactB, axisB, b->radius, &k.x, length, roundedSeparation, a, b) && (*(char*)&DAT_00555481) == 0)
                        return;
                }
            }
        }
    } else {
        double alongAxis = axisA->z * d.z + axisA->y * d.y + axisA->x * d.x;
        axial.x = (float)(alongAxis * axisA->x);
        axial.y = (float)(alongAxis * axisA->y);
        axial.z = (float)(alongAxis * axisA->z);
        radial.x = d.x - axial.x;
        radial.y = d.y - axial.y;
        radial.z = d.z - axial.z;
        double radialLength = radial.FUN_0022d110();
        if (radialLength > 9.99999997475243e-007f) {
            double axisGap = radialLength - (b->half + a->half);
            volatile float roundedAxisGap = (float)axisGap;
            if (axisGap <= margin) {
                double axialLength = axial.FUN_0022d110();
                double otherGap = axialLength - (b->radius + a->radius);
                if (otherGap <= margin) {
                    radialGap = (float)otherGap;
                    FloatBits_301e10 absAxisGap, absRadialGap;
                    absAxisGap.f = roundedAxisGap;
                    absAxisGap.u &= 0x7fffffff;
                    absRadialGap.f = radialGap;
                    absRadialGap.u &= 0x7fffffff;
                    if (absAxisGap.f < absRadialGap.f) {
                        contactA.x = axial.x * a->radius;
                        contactA.y = axial.y * a->radius;
                        contactA.z = axial.z * a->radius;
                        contactA.FUN_00011160(a->half, &radial);
                        Vec3_301e10 *origin = a->GetPos();
                        contactA.x = contactA.x + origin->x;
                        contactA.y = contactA.y + origin->y;
                        contactA.z = contactA.z + origin->z;
                        contactB.FUN_001f6bc0(&contactA, roundedAxisGap, &radial);
                        radial.x = radial.x * -1.0f;
                        radial.y = radial.y * -1.0f;
                        radial.z = radial.z * -1.0f;
                        FUN_00314be0(a, &contactA, b, &contactB, roundedAxisGap, &radial);
                    }
                }
            }
        }
    }
    FUN_00318bb0(a, b);
    FUN_00318910(a, b);
    FUN_00317700(a, b, 1, 1);
}
