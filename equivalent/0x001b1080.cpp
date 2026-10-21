// STATUS: equivalent (tools/equiv.py level 3: 20047 inputs, branch coverage 18/20, incomplete)
// FUN_001b1080 @ 0x001b1080
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" double sqrt(double);

struct V3_1b1080 {
    float x, y, z;
};

struct Mover_1b1080 {
    void FUN_00035660(V3_1b1080 *out);
};

struct Core_1b1080 {
    unsigned __int64 FUN_001d4f70();
};

float __cdecl FUN_00018a20(float x);
float __cdecl FUN_000186b0(float *value, float *lo, float *hi);

struct Slots_1b1080 {
    float hi;
    float lo;
    float d;
};

struct Obj_1b1080 {
    char pad0[0xe8];
    char clampFlag;
    char pade9[3];
    Core_1b1080 *core;
    char padf0[0x148 - 0xf0];
    int blocked;
    float FUN_001d8160();
};

int __stdcall FUN_001b1080(Obj_1b1080 *obj, Mover_1b1080 *mover, V3_1b1080 *out, int a4)
{
    if (obj->core->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004e1828)) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        return 0;
    }
    V3_1b1080 v;
    mover->FUN_00035660(&v);
    hulk_freg vlen2 = v.z * v.z + v.y * v.y + v.x * v.x;
    V3_1b1080 w = *out;
    Slots_1b1080 s;
    s.d = (float)sqrt(vlen2);
    if (!(s.d >= 0.01f))
        return 0;
    hulk_freg dot = w.z * v.z + w.y * v.y + w.x * v.x;
    hulk_freg wlen = (float)sqrt(w.z * w.z + w.y * w.y + w.x * w.x);
    hulk_freg c = dot / (wlen * s.d);
    if (c >= -1.0f && c <= 1.0f) {
        s.d = c;
    } else {
        s.d = 1.0f;
        if (!(c > 1.0f))
            s.d = -1.0f;
    }
    if (!(FUN_00018a20(s.d) < 1.57079637f))
        return 0;
    if (obj->blocked) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        return 0;
    }
    s.d = obj->FUN_001d8160();
    s.hi = 10000.0f;
    s.lo = 1.0f;
    FUN_000186b0(&s.d, &s.lo, &s.hi);
    if (obj->clampFlag && s.d < 200.0f)
        s.d = 200.0f;
    hulk_freg inv = 1.0f / (float)sqrt(s.d);
    out->x = out->x * inv;
    out->y = out->y * inv;
    out->z = out->z * inv;
    return 0;
}
