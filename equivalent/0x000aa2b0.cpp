// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 16/16)
// FUN_000aa2b0 @ 0x000aa2b0
#include "decls/address.h"
#include "compat/ptr.h"
struct Vec3_aa2b0 { float x, y, z; };

class Query_aa2b0 {
public:
    bool FUN_00201e00(Vec3_aa2b0 *a, Vec3_aa2b0 *b, int one, Vec3_aa2b0 *out2, Vec3_aa2b0 *out1, int z1, int z2);
};

struct World {
    char pad0[0x24];
    Query_aa2b0 *query;
};


hulk_freg __stdcall FUN_000aa2b0(Vec3_aa2b0 *v1, Vec3_aa2b0 *v2, float a3, float a4, float a5)
{
    hulk_freg m = (v1->y < v2->y) ? v2->y : v1->y;
    if (a3 < m)
        a3 = m;
    float lim = a5 + 0.2f;
    float c = a3 - a4;
    hulk_freg s = (c < lim) ? lim : c;

    Vec3_aa2b0 B = *v2;
    Vec3_aa2b0 A = *v1;
    Vec3_aa2b0 out1;
    Vec3_aa2b0 out2;
    B.y = s;
    A.y = s;
    bool ok = DAT_004dd700->query->FUN_00201e00(&A, &B, 1, &out2, &out1, 0, 0);
    float lo = s;
    float hi;
    if (!ok) {
        hi = s;
    } else {
        hi = 200.0f;
        if (hi - lo > 5.0f) {
            do {
                hulk_freg mid = (hi + lo) * 0.5f;
                B.y = mid;
                A.y = mid;
                ok = DAT_004dd700->query->FUN_00201e00(&A, &B, 1, &out1, &out2, 0, 0);
                if (!ok)
                    hi = mid;
                else
                    lo = mid;
            } while (hi - lo > 5.0f);
        }
    }
    hulk_freg r = hi + a4;
    return (a3 < r) ? r : a3;
}
