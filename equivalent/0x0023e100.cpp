// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// fight::WaitAction::vfunc_3 @ 0x0023e100
// fight::WaitAction::vfunc_3 @ 0x0023e100: interpolate between two offsets from a reference value
union FloatBits {
    float f;
    unsigned int u;
};

float __cdecl FUN_00238350(int v);

struct Range {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float Reference();
    char pad04[0xc];
    float lo;
    float hi;
};

namespace fight {

class WaitAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Range *range;
    int blend;
    float result;
};

bool WaitAction::vfunc_3(int a, int b)
{
    float ref = range->Reference();
    float t = range->lo - ref;
    double u = range->hi - ref;
    float d = t - u;
    FloatBits ad;
    ad.f = d;
    ad.u &= 0x7fffffff;
    float x;
    float y;
    if (ad.f <= 1e-05f) {
        result = t;
        return true;
    }
    if (u > t) {
        x = u - t;
        y = t;
    } else {
        x = d;
        y = u;
    }
    result = FUN_00238350(blend) * x + y;
    return true;
}

}
