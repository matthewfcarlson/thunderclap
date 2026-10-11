// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 22/22)
// choreo2::LocomotionStrafeDriver::vfunc_12 @ 0x00227100
struct Source {
    char pad0[8];
    int a;
    int b;
};

struct Anim {
    char pad0[0x10];
    float weight;
    char FUN_00288d10(int zero, int a, int b, float *outHi, float *outLo);
    float FUN_00288de0(int which, int zero, int a, int b);
};

struct Entry {
    Anim *anim;
    char pad04[0x204 - 4];
    float bias;
};

struct Blend {
    unsigned int entry;
    float weight;
    float pad;
};

float FUN_0004af40(int zero, float t, float x);

class LocomotionStrafeDriver {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12(Source *src, float *out);
    char pad04[0x24 - 4];
    float scale;
    char pad28[0x34 - 0x28];
    Entry entries[9];
    char padEnd[0x12ec - 0x34 - 9 * 0x208];
    unsigned int blendCount;
    Blend blends[1];
    char FUN_00222330(Source *src);
};

bool LocomotionStrafeDriver::vfunc_12(Source *src, float *out)
{
    if (blendCount == 0)
        return false;
    if (!FUN_00222330(src))
        return false;

    int a = src->a;
    int b = src->b;
    *out = 0.0f;
    bool result = false;
    float sum = 0.0f;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend *bl = &blends[i];
        sum = sum + bl->weight;
        float ratio = bl->weight / sum;
        Entry *e = &entries[bl->entry];
        Anim *anim = e->anim;
        if (anim) {
            float hi;
            float lo;
            if (anim->FUN_00288d10(0, a, b, &hi, &lo)) {
                float lowT = anim->FUN_00288de0(0, 0, a, b);
                float highT = anim->FUN_00288de0(1, 0, a, b);
                float t = anim->weight - 1.0f;
                float c = FUN_0004af40(0, t, t * scale + e->bias);
                float r;
                if (highT >= lowT) {
                    if (!(c >= lowT))
                        r = 1.0f;
                    else if (c < highT)
                        r = 0.0f;
                    else
                        r = 1.0f;
                } else {
                    if (!(c >= highT))
                        r = 0.0f;
                    else if (c < lowT)
                        r = 1.0f;
                    else
                        r = 0.0f;
                }
                result = true;
                *out = (r - *out) * ratio + *out;
            }
        }
    }
    return result;
}
