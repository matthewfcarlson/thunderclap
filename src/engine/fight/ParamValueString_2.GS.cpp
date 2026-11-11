// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002349e0..0x00234a90 (kind game, layer engine, confidence medium), dominant class fight::ParamValueString
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff45ca36 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff45ca36 {} using namespace fn_ff45ca36;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_ff45ca36 {
class Reader {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual bool Read(int a, int b, char* dst, int size);
};
namespace fight {
class ParamValueString {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(void* a, void* unused, Reader* reader);
    virtual bool f6(void* a, const char* text);
    int pad[1];
    int key0;
    int key1;
};
}


// 0x00234a10 fight::ParamValueString::vfunc_5 (121 B): equivalent/0x00234a10.cpp
// sym: ?vfunc_5@ParamValueString@fight@fn_ff45ca36@@UAE_NPAX0PAVReader@3@@Z @d3660de81d17 @w8c2bd7f28604
// STATUS: equivalent (tools/equiv.py level 3: 9032 inputs, branch coverage 2/2)
// fight::ParamValueString::vfunc_5 @ 0x00234a10
bool fight::ParamValueString::vfunc_5(void* a, void* unused, Reader* reader) {
    struct Frame {
        char text[0x400];
        int pad;                // (the original leaves a word between the buffer and the cookie)
    } f;
    f.text[0] = 0;
    memset(f.text + 1, 0, sizeof(f.text) - 1);
    bool ok = reader->Read(key0, key1, f.text, 0x400);
    if (ok)
        f6(a, f.text);
    return ok;
}

} // namespace fn_ff45ca36
