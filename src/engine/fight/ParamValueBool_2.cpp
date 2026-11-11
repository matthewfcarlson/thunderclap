// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234780..0x002348e0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueBool
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fff9a376 {
#define TREE_TU_END }
namespace fn_fff9a376 {} using namespace fn_fff9a376;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fff9a376 {
extern void* ParamValue_vftable;
extern "C" void __fastcall FUN_0027af50(void*);
typedef hulk_uintptr U32_2347b0;
extern void* MakeTemp(int);
extern "C" void* FUN_00266da0(void*);
extern "C" void* FUN_0008d6d0(int);
class Item {
  public:
    virtual void Release(int);
};
extern "C" void __cdecl Free(void*);
extern "C" char DAT_00427a18[];
struct Member_234860 {
    void Init(const char*);
};


// 0x00234780 FUN_00234780 (14 B): matches/0x00234780.cpp
// sym: ?FUN_00234780@fn_fff9a376@@YIXPAX@Z
void __fastcall FUN_00234780(void* self) {
    *(void**)self = &ParamValue_vftable;
    FUN_0027af50((char*)self + 8);
}

} // namespace fn_fff9a376

// 0x00234790 fight::ParamValue::vfunc_3 (3 B): matches/0x00234790.cpp
// sym: ?vfunc_3@ParamValue@fight@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void fight::ParamValue::vfunc_3(int a, int b) {}


// 0x002347a0 fight::ParamValue::vfunc_4 (3 B): matches/0x002347a0.cpp
// sym: ?vfunc_4@ParamValue@fight@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void fight::ParamValue::vfunc_4(int a, int b) {}

namespace fn_fff9a376 {

// 0x002347b0 FUN_002347b0 (91 B): matches/0x002347b0.cpp
// sym: _FUN_002347b0
extern "C" void FUN_002347b0(U32_2347b0** out, U32_2347b0* src, int count) {
    void* p = MakeTemp(0);
    p = FUN_00266da0(p);
    *out = (U32_2347b0*)FUN_0008d6d0(count * sizeof(U32_2347b0) + sizeof(U32_2347b0));
    int i;
    for (i = 0; i < count; ++i)
        (*out)[i] = src[i];
    (*out)[count] = 0;
    FUN_00266da0(p);
}


// 0x00234810 FUN_00234810 (71 B): matches/0x00234810.cpp
// sym: ?FUN_00234810@fn_fff9a376@@YAXPAPAPAVItem@1@PAH@Z
void __cdecl FUN_00234810(Item*** list, int* refs) {
    if (--*refs == 0) {
        if ((*list)[0]) {
            for (int i = 0; (*list)[i]; ++i) {
                Item* p = (*list)[i];
                if (p)
                    p->Release(1);
            }
        }
        Free(*list);
        *list = 0;
    }
}

} // namespace fn_fff9a376

// 0x00234860 FUN_00234860 (34 B): matches/0x00234860.cpp
// sym: ?FUN_00234860@ParamValueBool@fight@@QAEPAV12@PBD@Z
fight::ParamValueBool* fight::ParamValueBool::FUN_00234860(const char* value) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234860*)((char*)this + 8))->Init(value);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a18);
    return (fight::ParamValueBool*)(this);
}


// 0x00234890 fight::ParamValueBool::vfunc_5 (65 B): matches/0x00234890.cpp [wrapped: conflict: fight::ParamValue; fight::ParamValueBool; fight::Reader]
// sym: ?vfunc_5@ParamValueBool@fight@fn_00234890@@UAEDHHPAVReader@23@@Z
namespace fn_00234890 {
namespace fight {
class Reader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual char Read(int, int, int*);
};
class ParamValue {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int, Reader*);
    virtual void Set(int, int);
    int pad;
    int a;
    int b;
};
class ParamValueBool : public ParamValue {
  public:
    virtual char vfunc_5(int x, int y, Reader* r);
};
char ParamValueBool::vfunc_5(int x, int y, Reader* r) {
    int val;
    *(char*)&val = 0;
    int aa = a;
    int bb = b;
    char ok = r->Read(aa, bb, &val);
    if (ok)
        Set(x, val);
    return ok;
}
} // namespace fight
} // namespace fn_00234890

