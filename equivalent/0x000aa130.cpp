// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 2/2)
// FUN_000aa130 @ 0x000aa130
#include "compat/ptr.h"
struct Vec3_aa130 { float x, y, z; void FUN_0022d210(struct Mat_aa130* m); };
struct Mat_aa130 {
    float m[16];
    void FUN_0022ca90(Mat_aa130* a, Mat_aa130* b);
};

class Target_aa130 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(float f, int i);
    virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(int a);
    virtual void v13(); virtual void v14x(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(int a, int b, int c);
};

class Source_aa130 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual Mat_aa130* v14();
};

class Obj_aa130 {
public:
    char pad04[0x424];
    Target_aa130* target;
    Source_aa130* source;
    bool FUN_000aa130(int a, Mat_aa130* b, float* out);
};

bool Obj_aa130::FUN_000aa130(int a, Mat_aa130* b, float* out)
{
    if (target == 0)
        return false;
    target->v24(a, 0, 0);
    target->v12(0);
    target->v7();
    Mat_aa130 view = *source->v14();
    Mat_aa130 res;
    res.FUN_0022ca90(&view, b);
    view = res;
    out[0] = view.m[12];
    out[1] = view.m[13];
    out[2] = view.m[14];
    out[3] = view.m[8];
    out[4] = view.m[9];
    out[5] = view.m[10];
    out[6] = view.m[4];
    out[7] = view.m[5];
    out[8] = view.m[6];
    target->v6(1.0f, 1);
    target->v7();
    Mat_aa130* sm = source->v14();
    Vec3_aa130 t;
    t.x = sm->m[12];
    t.y = sm->m[13];
    t.z = sm->m[14];
    t.FUN_0022d210(b);
    hulk_freg dx = t.x - out[0];
    volatile float dy = t.y - out[1];
    volatile float dz = t.z - out[2];
    out[9] = dx * 999.99994f;
    out[10] = dy * 999.99994f;
    out[11] = dz * 999.99994f;
    return true;
}
