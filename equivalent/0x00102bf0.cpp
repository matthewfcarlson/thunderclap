// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 2/2)
// FUN_00102bf0 @ 0x00102bf0
// FUN_00102bf0: out = (target - origin), clamped to a maximum length
#include "compat/ptr.h"
struct V3_102bf0 {
    float x, y, z;
};

struct Anchor_102bf0 {
    void FUN_00059a50(V3_102bf0 *out);
};

class Mover_102bf0 {
public:
    char pad00[0x10];
    Anchor_102bf0 *anchor;
    float FUN_000356b0();
};

extern "C" double __cdecl sqrt(double);

extern "C" void __cdecl FUN_00102bf0(void *m, void *target, float speed, void * out_)
{
    V3_102bf0 * out = (V3_102bf0 *)out_;
    V3_102bf0 origin;
    ((Mover_102bf0 *)m)->anchor->FUN_00059a50(&origin);
    out->x = ((V3_102bf0 *)target)->x - origin.x;
    out->y = ((V3_102bf0 *)target)->y - origin.y;
    hulk_freg dz = ((V3_102bf0 *)target)->z - origin.z;      // the store of out->z leaves st0 unrounded for the length
    out->z = dz;
    double root = sqrt(out->x * out->x + out->y * out->y + dz * dz);
    hulk_freg len = (float)root;
    hulk_freg t = (float)(root / speed);
    hulk_freg limit = ((Mover_102bf0 *)m)->FUN_000356b0();
    hulk_freg clamped = (t < limit) ? t : limit;
    hulk_freg scale = clamped / len;
    out->x = scale * out->x;
    out->y = scale * out->y;
    out->z = scale * out->z;
}
