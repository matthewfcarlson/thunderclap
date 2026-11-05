#include "compat/ptr.h"
typedef unsigned int u32_59bf0;
struct Obj_59bf0 {
    char pad[0x18];
    u32_59bf0 value;
};
struct ThisWrap_00059bf0 {
    Obj_59bf0* FUN_00059ba0(u32_59bf0);
    hulk_uintptr FUN_00059bf0(u32_59bf0 param);
};
hulk_uintptr ThisWrap_00059bf0::FUN_00059bf0(u32_59bf0 param) {
    Obj_59bf0* p = this->FUN_00059ba0(param);
    if (p)
        return p->value;
    return 0;
}