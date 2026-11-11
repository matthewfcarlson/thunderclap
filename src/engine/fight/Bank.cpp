// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c670..0x0023c8a0 (kind game, layer engine, confidence high), dominant class fight::Bank
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1f0ad99 {
#define TREE_TU_END }
namespace fn_f1f0ad99 {} using namespace fn_f1f0ad99;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f1f0ad99 {
struct Node_23c670 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Node_23c670 *v8(void *ctx, float *weight);
    char pad04[0x10 - 4];
    int kind;
    char pad14[0x20 - 0x14];
    Node_23c670 *next;
    Node_23c670 *FUN_0023c300();
};
hulk_freg __cdecl FUN_00238350(void *ctx);
struct Bank_nv_23c670 {
    bool FUN_002333f0(void *ctx, int b);
};
extern void* hulk_at_004288b4[];
class Branch_23c870 {
  public:
     // FUN_00236d60, __thiscall, this in ecx
};
class Bank_23c870 : public Branch_23c870 {
  public:
    Bank_23c870* vfunc_5(signed char flags);
};

} // namespace fn_f1f0ad99

// 0x0023c670 fight::Bank::vfunc_8 (334 B): matches/0x0023c670.cpp
// sym: ?vfunc_8@Bank@fight@@UAEIII@Z
// fight::Bank::vfunc_8 @ 0x0023c670
hulk_uintptr fight::Bank::vfunc_8(hulk_uintptr __p0, unsigned int __p1) { void * ctx = (void *)__p0; int b = (int)__p1;

    if (!((Bank_nv_23c670*)this)->FUN_002333f0(ctx, b))
        return (unsigned int)(0);

    float sum = 0.0f;
    for (Node_23c670 *n = (*(Node_23c670 * *)&this->f_1c); n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node_23c670 *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node_23c670 *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            return (hulk_uintptr)(hit);
        sum = w + sum;
    }
    if (sum <= 0.0f)
        return (unsigned int)(0);

    float target = FUN_00238350(ctx) * sum;
    float acc = 0.0f;
    for (Node_23c670 *n = (*(Node_23c670 * *)&this->f_1c); n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node_23c670 *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node_23c670 *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            continue;
        acc = w + acc;
        if (target <= acc)
            return (hulk_uintptr)(hit);
    }
    return (unsigned int)(0);
}


// 0x0023c7c0 fight::Bank::vfunc_9 (169 B): equivalent/0x0023c7c0.cpp [wrapped: conflict: fight::Bank]
// sym: ?vfunc_9@Bank@fight@fn_0023c7c0@@UAE_NPAUInput_23c7c0@3@PAUObject@3@K@Z
namespace fn_0023c7c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 12/12)
// fight::Bank::vfunc_9 @ 0x0023c7c0

typedef unsigned __int64 Id_23c7c0;
struct Object {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual bool s13(); virtual Id_23c7c0 s14(); virtual void s15(); virtual void s16(Id_23c7c0); virtual void s17();
};
struct Input_23c7c0 { char pad[0x28]; unsigned long value; };
struct List_23c7c0 { void FUN_00236ec0(); void FUN_00237160(Id_23c7c0, unsigned long, Object*); };
namespace fight { struct Bank {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual bool vfunc_9(Input_23c7c0*,Object*,unsigned long);
 char pad[0x14]; List_23c7c0 list;
 void FUN_00233c50(Input_23c7c0*,Object*,unsigned long);
 void FUN_002337c0(Input_23c7c0*,Object*,int);
}; }
bool fight::Bank::vfunc_9(Input_23c7c0* input, Object* object, unsigned long arg) {
 if (!object->s13()) return false;
 Id_23c7c0 id=object->s14();
 if ((unsigned long)id != (*(unsigned long*)&DAT_004e5b30) || (unsigned long)(id>>32) != (*(unsigned long*)((char*)&DAT_004e5b30 + 4))) return false;
 object->s16(((Id_23c7c0)(*(unsigned long*)((char*)&DAT_004e5b30 + 4))<<32)|(*(unsigned long*)&DAT_004e5b30));
 FUN_00233c50(input,object,arg);
 list.FUN_00236ec0();
 if(object->s13()) {
  id=object->s14();
  if((unsigned long)id==(*(unsigned long*)&DAT_004e5b20) && (unsigned long)(id>>32)==(*(unsigned long*)((char*)&DAT_004e5b20 + 4)))
   list.FUN_00237160(((Id_23c7c0)(*(unsigned long*)((char*)&DAT_004e5b20 + 4))<<32)|(*(unsigned long*)&DAT_004e5b20),input->value,object);
 }
 FUN_002337c0(input,object,-1);
 object->s17();
 return true;
}
} // namespace fn_0023c7c0

namespace fn_f1f0ad99 {

// 0x0023c870 fight::Bank::vfunc_2 (36 B): matches/0x0023c870.cpp
// sym: ?vfunc_5@Bank_23c870@fn_f1f0ad99@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Bank_23c870* Bank_23c870::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_004288b4;
    ((fight::Branch *)(Branch_23c870 *)this)->FUN_00233970();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f1f0ad99
