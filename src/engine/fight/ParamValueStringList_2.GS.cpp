// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234a90..0x00234ba0 (kind game, layer engine, confidence medium), dominant class fight::ParamValueStringList
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fff40009 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fff40009 {} using namespace fn_fff40009;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fff40009 {
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
class ParamValueStringList {
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


// 0x00234b20 fight::ParamValueStringList::vfunc_5 (121 B): equivalent/0x00234b20.cpp
// sym: ?vfunc_5@ParamValueStringList@fight@fn_fff40009@@UAE_NPAX0PAVReader@3@@Z @3ade8aba0170 @w6bac13422216
// STATUS: equivalent (tools/equiv.py level 3: 9091 inputs, branch coverage 2/2)
// fight::ParamValueStringList::vfunc_5 @ 0x00234b20
bool fight::ParamValueStringList::vfunc_5(void* a, void* unused, Reader* reader) {
    char text[0x400] = "";
    bool ok = reader->Read(key0, key1, text, 0x400);
    if (ok)
        f6(a, text);
    return ok;
}

} // namespace fn_fff40009
