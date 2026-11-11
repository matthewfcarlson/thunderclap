// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235300..0x00235460 (kind game, layer engine, confidence medium), dominant class fight::ParamValueName
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_ff9a771c {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff9a771c {} using namespace fn_ff9a771c;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_ff9a771c {
class Part_235300 {
  public:
    void Init_0027af50();
};
namespace fight {
class ParamValueBool {
  public:
    hulk_intptr vt;
    int pad;
    Part_235300 part;
    ParamValueBool* vfunc_0(int);
};
}
extern "C" void __cdecl thunk_FUN_00267090(fight::ParamValueBool*);
class Part_2353c0 {
  public:
    void Init_0027af50();
};
namespace fight {
class ParamValueName {
  public:
    hulk_intptr vt;
    int pad;
    Part_2353c0 part;
    ParamValueName* vfunc_0(int);
};
}
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(fight::ParamValueName*);


// 0x00235300 fight::ParamValueBool::vfunc_0 (39 B): matches/0x00235300.cpp
// sym: ?vfunc_0@ParamValueBool@fight@fn_ff9a771c@@QAEPAV123@H@Z
fight::ParamValueBool* fight::ParamValueBool::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ff9a771c

// 0x00235330 fight::ParamValueInt::vfunc_0 (39 B): matches/0x00235330.cpp [wrapped: merged class would differ: ParamValueInt: virtual f0 at slot 0, merged 7]
// sym: ?f0@ParamValueInt@fn_00235330@@UAEPAV12@H@Z
namespace fn_00235330 {
extern "C" char DAT_004279fc[];
class Inner_235330 {
  public:
    void Init_0027af50();
};
class ParamValue {
  public:
    virtual ParamValue* f0(int);
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[4];
    Inner_235330 inner;
};
class ParamValueInt : public ParamValue {
  public:
    virtual ParamValueInt* f0(int);
};
extern void Cleanup_0008d330(ParamValueInt*);
ParamValueInt* ParamValueInt::f0(int flags) {
    int* q = (int*)this;
    *(hulk_intptr*)q = ((hulk_intptr)DAT_004279fc);
    inner.Init_0027af50();
    if (flags & 1)
        Cleanup_0008d330(this);
    return this;
}
} // namespace fn_00235330


// 0x00235360 fight::ParamValueFloat::vfunc_0 (39 B): matches/0x00235360.cpp [wrapped: merged class would differ: ParamValueFloat: virtual vfunc_0 hides a base virtual]
// sym: ??0ParamValueFloat@fn_00235360@@QAE@I@Z
namespace fn_00235360 {
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int pad;
};
class Sub_235360 {
  public:
    Sub_235360();
};
class ParamValueFloat : public ParamValue {
  public:
    ParamValueFloat(unsigned int);
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_5();
    Sub_235360 sub;
};
extern void __cdecl thunk_FUN_00267090(ParamValueFloat*);
ParamValueFloat::ParamValueFloat(unsigned int flags) {
    if (flags & 1)
        thunk_FUN_00267090(this);
}
} // namespace fn_00235360


// 0x00235390 fight::ParamValueString::vfunc_0 (39 B): matches/0x00235390.cpp [wrapped: merged class would differ: ParamValueString: field part: Field(+0xc Part_235390 part) vs Field(+0x8 Part_235390 part)]
// sym: ?vfunc_0@ParamValueString@fight@fn_00235390@@UAEPAV123@H@Z
namespace fn_00235390 {
extern int hulk_at_004279fc;
class ParamValue {
  public:
    virtual ParamValue* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    int pad;
};
class Part_235390 {
  public:
    void Init_0027af50();
};
namespace fight { class ParamValueString : public ParamValue {
  public:
    virtual ParamValueString* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_5();
    Part_235390 part;
}; }
extern void thunk_FUN_00267090(fight::ParamValueString*);
fight::ParamValueString* fight::ParamValueString::vfunc_0(int x) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_004279fc;
    part.Init_0027af50();
    if (x & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00235390

namespace fn_ff9a771c {

// 0x002353c0 fight::ParamValueName::vfunc_0 (39 B): matches/0x002353c0.cpp
// sym: ?vfunc_0@ParamValueName@fight@fn_ff9a771c@@QAEPAV123@H@Z
// Same code shape as 0x00235300 (propagated; names are from that function)
fight::ParamValueName* fight::ParamValueName::vfunc_0(int flag) {
    vt = (hulk_intptr)&base_vtable;
    part.Init_0027af50();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ff9a771c

// 0x002353f0 fight::ParamValueName::vfunc_5 (100 B): equivalent/0x002353f0.cpp [wrapped: conflict: fight::ParamValueName]
// sym: ?vfunc_5@ParamValueName@fight@fn_002353f0@@UAEHHHPAVSink_2353f0@3@@Z @9cb6b108476c @w0feba7ea757c
namespace fn_002353f0 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// fight::ParamValueName::vfunc_5 @ 0x002353f0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif


struct Key_2353f0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};

extern "C" void FUN_00364130();

class Sink_2353f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7(int a, int b, Key_2353f0 *k);
};

namespace fight { class ParamValueName {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(int a1, int a2, Sink_2353f0 *sink);
    virtual void v6();
    virtual Key_2353f0 *v7(int a1);
    int f4;
    int f8;
    int fc;
}; }

int fight::ParamValueName::vfunc_5(int a1, int a2, Sink_2353f0 *sink)
{
    if (((*(unsigned*)&DAT_004e5bc8) & 1) == 0) {
        (*(unsigned*)&DAT_004e5bc8) |= 1;
        (*(Key_2353f0*)&DAT_004e5bc0).FUN_0027af00();
        atexit(FUN_00364130);
    }
    Key_2353f0 *k = v7(a1);
    if (k == 0)
        k = ((Key_2353f0*)&DAT_004e5bc0);
    return sink->v7(f8, fc, k);
}
} // namespace fn_002353f0

