// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleDamageTrack::vfunc_12 @ 0x0005a510
#include "compat/ptr.h"
#include "gen/global.h"

void *__cdecl FUN_0008d690(unsigned int size);

struct Holder_5a510 {
    char pad0[0x104];
    void *anim;
};

struct Res_5a510 {
    char pad00[0x330];
    Holder_5a510 *primary;
    Holder_5a510 *secondary;
};

struct Resolver_5a510 {
    Res_5a510 *FUN_00059a30();
};

struct Target_5a510 {
    Resolver_5a510 *FUN_000592a0();
};

struct Effect_5a510 {
    Effect_5a510 *FUN_0001d9b0(void *anim, int a, int b);
};

hulk_intptr CGrappleDamageTrack::vfunc_12(hulk_intptr __p0) { Target_5a510 * target = (Target_5a510 *)__p0;

    if (target == 0) {
        return (int)(0);
    }
    Resolver_5a510 *resolver = target->FUN_000592a0();
    if (resolver == 0) {
        return (int)(0);
    }
    Res_5a510 *res = resolver->FUN_00059a30();
    if (res == 0) {
        return (int)(0);
    }
    Holder_5a510 *holder = res->secondary;
    if (holder == 0) {
        holder = res->primary;
        if (holder == 0) {
            return (int)(0);
        }
    }
    void *anim = holder->anim;
    if (anim == 0) {
        return (int)(0);
    }
    Effect_5a510 *mem = (Effect_5a510 *)FUN_0008d690(0x28);
    if (mem == 0) {
        return (int)(0);
    }
    return (hulk_intptr)(mem->FUN_0001d9b0(anim, this->f_10, this->f_14));
}
