// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 24/24)
// FUN_001fc150 @ 0x001fc150
struct Vec3_1fc150 {
    float x, y, z;
    float FUN_0022d110();
};

void __cdecl FUN_00224d70(float angle, Vec3_1fc150 *v);

class CTriggerVolume_1fc150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(Vec3_1fc150 point);
    char pad04[0xb0 - 4];
    Vec3_1fc150 minimum;
    Vec3_1fc150 maximum;
    float angle;

    void FUN_001fbec0(Vec3_1fc150 *pivot);
    Vec3_1fc150 *FUN_001fc150(Vec3_1fc150 *out, const Vec3_1fc150 *a, const Vec3_1fc150 *b);
};

Vec3_1fc150 *CTriggerVolume_1fc150::FUN_001fc150(Vec3_1fc150 *out, const Vec3_1fc150 *a, const Vec3_1fc150 *b)
{
    struct Frame {
        Vec3_1fc150 p;
        Vec3_1fc150 r;
        Vec3_1fc150 pivot;
    } fr;

    fr.r.x = 0.0f;
    fr.r.y = 0.0f;
    fr.r.z = 0.0f;
    if (!vfunc_8(*a) && vfunc_8(*b)) {
        fr.p = *a;
        if (angle != 0.0f) {
            FUN_001fbec0(&fr.pivot);
            fr.p.x = fr.p.x - fr.pivot.x;
            fr.p.y = fr.p.y - fr.pivot.y;
            fr.p.z = fr.p.z - fr.pivot.z;
            FUN_00224d70(-angle, &fr.p);
            fr.p.x = fr.pivot.x + fr.p.x;
            fr.p.y = fr.pivot.y + fr.p.y;
            fr.p.z = fr.pivot.z + fr.p.z;
        }
        if (fr.p.x < minimum.x)
            fr.r.x = -1.0f;
        else if (fr.p.x > maximum.x)
            fr.r.x = 1.0f;
        if (fr.p.y < minimum.y)
            fr.r.y = -1.0f;
        else if (fr.p.y > maximum.y)
            fr.r.y = 1.0f;
        if (fr.p.z < minimum.z)
            fr.r.z = -1.0f;
        else if (fr.p.z > maximum.z)
            fr.r.z = 1.0f;
        fr.r.FUN_0022d110();
        FUN_00224d70(angle, &fr.r);
    }
    out->x = fr.r.x;
    out->y = fr.r.y;
    out->z = fr.r.z;
    return out;
}
