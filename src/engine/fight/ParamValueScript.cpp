// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234ba0..0x00234cc0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueScript
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f1ee0f39 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1ee0f39 {} using namespace fn_f1ee0f39;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f1ee0f39 {
class ParamValueStringList_234bd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void* get(void*);
};
namespace fight {
class ParamValueNameList : public ParamValueStringList_234bd0 {
  public:
    bool vfunc_6(void*, void*);
};
}
class Receiver_234bd0 {
  public:
    void run_0027b040(void*);
};
extern void* hulk_at_004279fc[];
extern void* hulk_at_00427b00[];
class Sub_234c00 {
  public:
    void Init_0027b0e0(int a);
};
class ParamValueScript_234c00 {
  public:
    void* vptr;
    char pad[4];
    Sub_234c00 sub;
    ParamValueScript_234c00(hulk_intptr a);
};
void* __cdecl FUN_00238190(int a);
extern "C" char* __cdecl FUN_00266e00(void* heap, int size);
void __cdecl thunk_FUN_00267090(void* p);
class Stream {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual bool Read(int a, int b, char* buf, int len);
    virtual void s9(); virtual void s10(); virtual void s11();
    virtual bool Measure(int a, int b, int* len);
};
namespace fight {
class ParamValueScript {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2, Stream* in);
    virtual void vfunc_6(int a1, char* text, int len);
    char pad[4];
    int f8, fc;
};
}


// 0x00234bd0 fight::ParamValueNameList::vfunc_6 (36 B): matches/0x00234bd0.cpp
// sym: ?vfunc_6@ParamValueNameList@fight@fn_f1ee0f39@@QAE_NPAX0@Z
// Same code shape as 0x00234ac0 (propagated; names are from that function)
bool fight::ParamValueNameList::vfunc_6(void* a, void* b) {
    void* x = get(a);
    if (!x)
        return false;
    ((Receiver_234bd0*)x)->run_0027b040(b);
    return true;
}


// 0x00234c00 FUN_00234c00 (34 B): matches/0x00234c00.cpp
// sym: ??0ParamValueScript_234c00@fn_f1ee0f39@@QAE@H@Z
ParamValueScript_234c00::ParamValueScript_234c00(hulk_intptr a) {
    vptr = hulk_at_004279fc;
    sub.Init_0027b0e0(a);
    vptr = hulk_at_00427b00;
}


// 0x00234c30 fight::ParamValueScript::vfunc_5 (138 B): equivalent/0x00234c30.cpp
// sym: ?vfunc_5@ParamValueScript@fight@fn_f1ee0f39@@UAE_NHHPAVStream@3@@Z @c0eb3f2d86d3 @wd2aee8669074
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// fight::ParamValueScript::vfunc_5 @ 0x00234c30
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x00267090
bool fight::ParamValueScript::vfunc_5(int a1, int, Stream* in) {
    int len = 0;
    if (!in->Measure(f8, fc, &len)) return false;
    char* buf = FUN_00266e00(FUN_00238190(1), len + 1);
    buf[0] = 0;
    bool ok = in->Read(f8, fc, buf, len + 1);
    if (ok)
        vfunc_6(a1, buf, len);
    thunk_FUN_00267090(buf);
    return ok;
}

} // namespace fn_f1ee0f39
