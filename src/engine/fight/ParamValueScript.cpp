// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234c00..0x00234cc0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueScript
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1ee0f39 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1ee0f39 {} using namespace fn_f1ee0f39;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f1ee0f39 {
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


} // namespace fn_f1ee0f39

// 0x00234c00 FUN_00234c00 (34 B): matches/0x00234c00.cpp
// sym: ??0ParamValueScript@fight@@QAE@PBD@Z
// (gx4, D18) the constructor the parameter registrations call (`new ParamScript<T>(name, setter)`)
::fight::ParamValueScript::ParamValueScript(const char* name) : ::fight::ParamValue(name) {}

namespace fn_f1ee0f39 {


// 0x00234c30 fight::ParamValueScript::vfunc_5 (138 B): equivalent/0x00234c30.cpp
// sym: ?vfunc_5@ParamValueScript@fight@fn_f1ee0f39@@UAE_NHHPAVStream@3@@Z @c0eb3f2d86d3 @wd2aee8669074 @v071a33a1a32e
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
