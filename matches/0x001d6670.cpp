#include "gen/global.h"
#include "compat/ptr.h"
struct Obj_1d6670 {
    char pad0[0x40];
    int value;
    char pad1[0xa8];
    void* context;
};
struct CSPHulkPropInstance_nv_1d6670 {
    int Get(int);
};
extern const float g_one_1d6670;
extern const float g_hundredth;
extern const float g_factor;
hulk_freg __fastcall FUN_001d6670(Obj_1d6670* self) {
    int result = ((CSPHulkPropInstance_nv_1d6670*)(((CSPHulkPropInstance*)self->context)))->Get(self->value);
    bool scale = result == 2;
    hulk_freg value = 1.0f;
    if (result == 3)
        value = 0.01f;
    if (scale)
        value *= 0.025f;
    return value;
}