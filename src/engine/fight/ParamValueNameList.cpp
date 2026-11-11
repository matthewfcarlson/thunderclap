// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235460..0x00235530 (kind game, layer engine, confidence medium), dominant class fight::ParamValueNameList
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_faf04b50 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faf04b50 {} using namespace fn_faf04b50;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_faf04b50 {
class Part_235460 {
  public:
    void Init();
};
namespace fight {
class ParamValueStringList {
  public:
    hulk_intptr vt;
    int pad;
    Part_235460 part;
    ParamValueStringList* vfunc_0(int);
};
}
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueStringList*);
class Sub_235490 {
  public:
    void init();
};
class ParamValueNameList {
  public:
    virtual ParamValueNameList* f0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    int pad;
    Sub_235490 sub;
};
extern void __cdecl thunk_FUN_00267090(ParamValueNameList*);
} // namespace fn_faf04b50
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_faf04b50 {
struct Key_2354c0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};
extern "C" void FUN_00364140();
class Sink_2354c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7(int a, int b, Key_2354c0 *k);
};
namespace fight {
class ParamValueNameList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(int a1, int a2, Sink_2354c0 *sink);
    virtual void v6();
    virtual Key_2354c0 *v7(int a1);
    int f4;
    int f8;
    int fc;
};
}


// 0x00235460 fight::ParamValueStringList::vfunc_0 (39 B): matches/0x00235460.cpp
// sym: ?vfunc_0@ParamValueStringList@fight@fn_faf04b50@@QAEPAV123@H@Z
// Same code shape as 0x00235300 (propagated; names are from that function)
fight::ParamValueStringList* fight::ParamValueStringList::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00235490 fight::ParamValueNameList::vfunc_0 (39 B): matches/0x00235490.cpp
// sym: ?f0@ParamValueNameList@fn_faf04b50@@UAEPAV12@H@Z
ParamValueNameList* ParamValueNameList::f0(int flag) {
    ParamValueNameList* p = this;
    *(void**)p = (void*)((hulk_intptr)DAT_004279fc);
    p->sub.init();
    if (flag & 1)
        thunk_FUN_00267090(p);
    return p;
}


// 0x002354c0 fight::ParamValueNameList::vfunc_5 (100 B): equivalent/0x002354c0.cpp
// sym: ?vfunc_5@ParamValueNameList@fight@fn_faf04b50@@UAEHHHPAVSink_2354c0@3@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// fight::ParamValueNameList::vfunc_5 @ 0x002354c0
int fight::ParamValueNameList::vfunc_5(int a1, int a2, Sink_2354c0 *sink)
{
    Key_2354c0 *k = v7(a1);
    if (k == 0) {
        if ((DAT_004e5bd8 & 1) == 0) {
            DAT_004e5bd8 |= 1;
            (*(Key_2354c0*)&DAT_004e5bd0).FUN_0027af00();
            atexit(FUN_00364140);
        }
        k = ((Key_2354c0*)&DAT_004e5bd0);
    }
    return sink->v7(f8, fc, k);
}

} // namespace fn_faf04b50
