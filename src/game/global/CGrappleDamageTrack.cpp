// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a4c0..0x0005a590 (kind game, layer game, confidence medium), dominant class CGrappleDamageTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7840bc1 {
#define TREE_TU_END }
namespace fn_f7840bc1 {} using namespace fn_f7840bc1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7840bc1 {
struct A_5a4c0 {
};
struct B_5a4c0 {
    void* second();
};
struct Data_5a4c0 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
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
};
struct Effect_5a510 {
    Effect_5a510 *FUN_0001d9b0(void *anim, int a, int b);
};

} // namespace fn_f7840bc1

// 0x0005a4c0 CGrappleDamageTrack::vfunc_11 (70 B): matches/0x0005a4c0.cpp
// sym: ?vfunc_11@CGrappleDamageTrack@@UAEPAXH@Z
void* CGrappleDamageTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5a4c0*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5a4c0*)a)->second();
            if (b) {
                Data_5a4c0* d = (Data_5a4c0*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005a510 CGrappleDamageTrack::vfunc_12 (123 B): equivalent/0x0005a510.cpp
// sym: ?vfunc_12@CGrappleDamageTrack@@UAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleDamageTrack::vfunc_12 @ 0x0005a510
hulk_intptr CGrappleDamageTrack::vfunc_12(hulk_intptr __p0) { Target_5a510 * target = (Target_5a510 *)__p0;

    if (target == 0) {
        return (int)(0);
    }
    Resolver_5a510 *resolver = ((Resolver_5a510 *)((owners::Object_592a0 *)target)->FUN_000592a0());
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
    return (hulk_intptr)(mem->FUN_0001d9b0(anim, this->damage, this->damageMax));
}

