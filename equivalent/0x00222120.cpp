// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00222120 @ 0x00222120
#include "decls/data/engine/unknown.h"

struct Vec3 { float x, y, z; };
struct Helper { void FUN_0022b4d0(float *source, Vec3 *out); };
struct Object {
    char pad[0x40];
    Helper helper;
    char pad2[0x0f];
    int mode;
    Vec3 *FUN_00222120(Vec3 *result);
    void FUN_0022c3b0(float *source, Vec3 *out);
};
Vec3 *Object::FUN_00222120(Vec3 *result) {
    Vec3 value;
    if (mode == 0 || mode == 2)
        FUN_0022c3b0(((float*)&DAT_004c9d60), &value);
    else if (mode == 1)
        helper.FUN_0022b4d0(((float*)&DAT_004c9d60), &value);
    *result = value;
    return result;
}