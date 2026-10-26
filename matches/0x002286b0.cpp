#include "decls/data/engine/choreo2.h"

struct Vec3_2286b0 {
    unsigned int a, b, c;
};
extern void __cdecl FUN_00224d70(unsigned int, Vec3_2286b0*);
struct Obj_2286b0 {
    char pad[0x8ac];
    unsigned int value;
    Vec3_2286b0 Get();
};
Vec3_2286b0 Obj_2286b0::Get() {
    Vec3_2286b0 local;
    local.a = (*(unsigned int*)&DAT_004c9e90);
    local.b = (*(unsigned int*)&DAT_004c9e94);
    local.c = (*(unsigned int*)&DAT_004c9e98);
    FUN_00224d70(value, &local);
    return local;
}
