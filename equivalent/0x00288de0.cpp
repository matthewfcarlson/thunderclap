// STATUS: equivalent (tools/equiv.py level 3: 235 inputs, branch coverage 12/12)
// FUN_00288de0 @ 0x00288de0
#include "compat/ptr.h"
struct Entry_288de0 {
    unsigned int key0;
    unsigned int key1;
    float offset;
    float scale;
    float pad[2];
};

struct Curve_288de0 {
    char pad0[0x10];
    float limit;
    char pad1[0x20];
    unsigned int count;
    Entry_288de0 *entries;
    hulk_freg FUN_00288de0(int slot, float x, unsigned int key0, unsigned int key1);
};

hulk_freg Curve_288de0::FUN_00288de0(int slot, float x, unsigned int key0, unsigned int key1)
{
    Entry_288de0 *e = entries;
    if (e == 0) {
        return 0.0f;
    }
    for (unsigned int i = 0; i < count; i++) {
        if (e->key0 == key0 && e->key1 == key1) {
            float *f = (float *)((char *)entries + (slot + i * 3) * 8);
            float v = x * f[3] + f[2];
            if (!(v >= limit)) {
                return v;
            }
            return v - limit;
        }
        e++;
    }
    return 0.0f;
}
