// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 24/24)
// CSmartPropDistanceCondition::vfunc_7 @ 0x0004c980
extern "C" double __cdecl sqrt(double);

struct V3 { float x, y, z; };

class Context { public: char pad[4]; };

struct Tgt {
    char pad[0x40];
    V3 pos;
};

struct Ent {
    Tgt* FUN_001d72e0();
};

struct Elem {
    char data[64];
    void FUN_0022c2b0(const V3* in, V3* out);
};

struct Mgr {
    char pad[0x1c];
    Elem* elems;
    unsigned int FUN_002843a0(int a, int b);
};

struct Owner {
    char pad0[0x120];
    Mgr* mgr;
    char pad1[0x3a4 - 0x124];
    Tgt* fallback;
    Ent* FUN_00035ef0(int a);
    void FUN_00035630(const V3* in, V3* out);
};

Context* __fastcall FUN_000592a0(void* obj);
Owner* __fastcall FUN_00059a30(Context* ctx);
char __cdecl FUN_00018960(float a, float b, float c);

class CSmartPropDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(void* params);
    char pad04[8];
    unsigned int mode;
    float threshold;
    char pad14[4];
    int f18;
    int f1c;
    V3 offset;
};

char CSmartPropDistanceCondition::vfunc_7(void* params)
{
    Owner* owner = FUN_00059a30(FUN_000592a0(params));
    Tgt* tgt;
    if (owner->FUN_00035ef0(0) != 0 && (tgt = owner->FUN_00035ef0(0)->FUN_001d72e0()) != 0) {
    } else {
        tgt = owner->fallback;
        if (tgt == 0)
            return 0;
    }
    V3 t = tgt->pos;
    V3 out;
    out.x = 0.0f;
    out.y = 0.0f;
    out.z = 0.0f;
    if ((f18 | f1c) != 0) {
        owner->FUN_00035630(&offset, &out);
    } else {
        unsigned int idx = owner->mgr->FUN_002843a0(0, 0);
        if (idx == 0xffff)
            return 0;
        owner->mgr->elems[idx].FUN_0022c2b0(&offset, &out);
    }
    float dx = out.x - t.x;
    float dy = out.y - t.y;
    float dz = out.z - t.z;
    float dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    switch (mode) {
    case 0: return dist < threshold;
    case 1: return dist <= threshold;
    case 2: return (char)FUN_00018960(dist, threshold, 1e-5f);
    case 3: return (char)FUN_00018960(dist, threshold, 1e-5f) == 0;
    case 4: return dist >= threshold;
    case 5: return dist > threshold;
    }
    return 0;
}
