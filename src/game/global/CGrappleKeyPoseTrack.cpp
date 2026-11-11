// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a680..0x0005a740 (kind game, layer game, confidence medium), dominant class CGrappleKeyPoseTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf3f91f {
#define TREE_TU_END }
namespace fn_fcf3f91f {} using namespace fn_fcf3f91f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcf3f91f {
struct A_5a680 {
};
struct B_5a680 {
    void* second();
};
struct Data_5a680 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
struct Settings;
struct Slot_5a6d0 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5a6d0 {
    char pad00[0x330];
    Slot_5a6d0* primary;
    Slot_5a6d0* secondary;
};
struct Context_5a6d0 {
    Fighter_5a6d0* FUN_00059a30();
};
struct Owner_5a6d0 {
};
struct Created_5a6d0 {
    void* FUN_0001d100(CGrappleKeyPoseTrack* track, Settings* settings);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int size);

} // namespace fn_fcf3f91f

// 0x0005a680 CGrappleKeyPoseTrack::vfunc_11 (70 B): matches/0x0005a680.cpp
// sym: ?vfunc_11@CGrappleKeyPoseTrack@@UAEPAXH@Z
// Same code shape as 0x0005a4c0 (propagated; names are from that function)
void* CGrappleKeyPoseTrack::vfunc_11(hulk_intptr param) {
    if (param) {
        void* a = ((void *)((owners::Object_592a0 *)(((A_5a680*)param)))->FUN_000592a0());
        if (a) {
            void* b = ((B_5a680*)a)->second();
            if (b) {
                Data_5a680* d = (Data_5a680*)b;
                if (d->p334)
                    return (void*)((int*)((char*)d->p334 + 0xdc));
                if (d->p330)
                    return (void*)((int*)((char*)d->p330 + 0xdc));
            }
        }
    }
    return (void*)(0);
}


// 0x0005a6d0 CGrappleKeyPoseTrack::vfunc_12 (105 B): equivalent/0x0005a6d0.cpp
// sym: ?vfunc_12@CGrappleKeyPoseTrack@@UAEHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleKeyPoseTrack::vfunc_12 @ 0x0005a6d0
hulk_intptr CGrappleKeyPoseTrack::vfunc_12(hulk_intptr __p0) { Owner_5a6d0 * owner = (Owner_5a6d0 *)__p0;

    if (owner == 0)
        return (int)(0);
    Context_5a6d0* ctx = ((Context_5a6d0 *)((owners::Object_592a0 *)owner)->FUN_000592a0());
    if (ctx == 0)
        return (int)(0);
    Fighter_5a6d0* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return (int)(0);
    Slot_5a6d0* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return (int)(0);
    Settings* settings = slot->settings;
    if (settings == 0)
        return (int)(0);
    Created_5a6d0* c = static_cast<Created_5a6d0*>(FUN_0008d690(0x30));
    if (c == 0)
        return (int)(0);
    return (hulk_intptr)(c->FUN_0001d100(this, settings));
}

