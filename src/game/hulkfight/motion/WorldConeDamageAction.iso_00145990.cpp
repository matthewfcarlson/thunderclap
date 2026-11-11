// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00143100..0x00146900 (kind game, layer game, confidence high), dominant class hulkfight::motion::WorldConeDamageAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00145990 FUN_00145990 (358 B): matches/0x00145990.cpp [isolated: conflict: Alloc; on include/gen/ and not mergeable]
// sym: ?FUN_00145990@@YAXXZ
#include "decls/data/game/hulkfight/motion.h"
// data: gCounter_145990 = DAT_004e0fa4
#include "gen/fight.h"

extern "C" void __cdecl FUN_00143610();
extern "C" void __cdecl FUN_00143630();
extern "C" void __cdecl FUN_00143650();
extern "C" void __cdecl FUN_00143670();
extern "C" void __cdecl FUN_00143690();
extern "C" void __cdecl FUN_001436b0();
extern "C" char DAT_0041324c[];
extern int gArray_145990;
extern "C" void* Alloc(hulk_uintptr);
struct Obj_145990 {
    void* vf;
    char pad[12];
    hulk_intptr v;
    char rest[4];
};
extern "C" void FUN_002347b0(void*, Obj_145990**, int);

void FUN_00145990() {
    if ((*(int*)&DAT_004e0fa4) == 0) {
        Obj_145990* a[6];
        Obj_145990* p;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeBegin");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_00143610);
            a[0] = p;
        } else
            a[0] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeOn");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_00143630);
            a[1] = p;
        } else
            a[1] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeOff");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_00143650);
            a[2] = p;
        } else
            a[2] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("timeEnd");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_00143670);
            a[3] = p;
        } else
            a[3] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("motionBlur");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_00143690);
            a[4] = p;
        } else
            a[4] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            ((fight::ParamValueFloat *)p)->FUN_00234960("motionBlurParallax");
            p->vf = (void*)((hulk_intptr)DAT_0041324c);
            p->v = ((hulk_intptr)(void (__cdecl*)())&FUN_001436b0);
            a[5] = p;
        } else
            a[5] = 0;
        FUN_002347b0((void*)((hulk_intptr)DAT_004e0fa0), a, 6);
    }
    ++(*(int*)&DAT_004e0fa4);
}

