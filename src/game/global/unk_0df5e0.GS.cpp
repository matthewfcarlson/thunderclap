// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000df5e0..0x000dfd70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f983911a {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f983911a {} using namespace fn_f983911a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f983911a {
extern "C" int __cdecl FUN_00294c70(const char* src, unsigned short* dst, int max);
class TextSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual float Measure(unsigned short* wide);    // slot 10
    hulk_freg FUN_000dfbf0(const char* text);
};


// 0x000dfbf0 FUN_000dfbf0 (113 B): matches/0x000dfbf0.cpp
// sym: ?FUN_000dfbf0@TextSink@fn_f983911a@@QAEMPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// FUN_000dfbf0 @ 0x000dfbf0
hulk_freg TextSink::FUN_000dfbf0(const char* text)
{
    struct Frame {
        unsigned short wide[0x200];
    } f;
    if (text == 0) {
        return 0.0f;
    }
    FUN_00294c70(text, f.wide, 0x200);
    float r = Measure(f.wide);
    return r;
}

} // namespace fn_f983911a
