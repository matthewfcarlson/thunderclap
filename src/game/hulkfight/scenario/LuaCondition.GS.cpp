// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1290..0x001a1ed0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::LuaCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f21f790b {
#define TREE_TU_END }
namespace fn_f21f790b {} using namespace fn_f21f790b;
#include "game/hulkfight/scenario.h"

// ---- declarations shared by the functions below
namespace fight {
class Params_1a14f0 {
public:
    virtual void v0();
};
}
namespace fn_f21f790b {
class CFightParams_1a14f0 : public fight::Params_1a14f0 {
public:
    virtual void v1();
};
struct Blob_1a14f0 {
    char data[0xe0];
};
class CScenarioParams_1a14f0 : public fight::Params_1a14f0 {
public:
    virtual void v1();
    char pad[4];
    int f8;
    Blob_1a14f0 *FUN_001d03c0();
};
struct LuaMgr {
    char pad0[8];
    void *L;
    bool FUN_001d1cb0();
    bool FUN_001d1d30();
    void FUN_001d2ee0(CFightParams_1a14f0 *p);
};
extern "C" LuaMgr *FUN_001d4c90();
extern "C" int FUN_00267760(char *buf, int n, const char *fmt, ...);
extern "C" void *FUN_0008d6d0(unsigned int n);
void FUN_0008d340(void *p);
extern "C" int FUN_00213160(void *L, int idx);
extern "C" void FUN_00212d80(void *L, int idx);
extern "C" unsigned int FUN_001d0440();
extern "C" void FUN_001d0430(unsigned int v);

} // namespace fn_f21f790b

// 0x001a14f0 hulkfight::scenario::LuaCondition::vfunc_6 (444 B): equivalent/0x001a14f0.cpp
// sym: ?vfunc_6@LuaCondition@scenario@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 14900 inputs, branch coverage 18/18)
// hulkfight::scenario::LuaCondition::vfunc_6 @ 0x001a14f0
bool hulkfight::scenario::LuaCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; fight::Params_1a14f0 * params = (fight::Params_1a14f0 *)__p1; hulk_intptr c = (hulk_intptr)__p2;

    struct Frame {
        char pad[0x18];
        char buf[0x100];
        Blob_1a14f0 copy;
        int pad1f8;
    } fr;
    LuaMgr *mgr = FUN_001d4c90();
    if (mgr == 0) {
        return false;
    }
    fr.buf[0] = 0;
    FUN_00267760(fr.buf, 0x100, "DO NOT USE THIS IN RELEASE MODE!  Talk to Kevin...");
    mgr->FUN_001d1cb0();
    ((owners::Thing_1d1d50 *)mgr)->FUN_001d1d50((hulk_uintptr)"node", (hulk_uintptr)(fr.buf));
    mgr->FUN_001d1d30();
    CScenarioParams_1a14f0 *sp = dynamic_cast<CScenarioParams_1a14f0 *>(params);
    if (sp != 0) {
        unsigned int v = sp->f8;
        if (FUN_001d0440() != v) {
            FUN_001d0430(sp->f8);
            fr.copy = *sp->FUN_001d03c0();
            ((owners::Dispatcher_1cb170 *)&(fr.copy))->FUN_001cb170();
        }
    } else {
        CFightParams_1a14f0 *fp = dynamic_cast<CFightParams_1a14f0 *>(params);
        if (fp != 0)
            mgr->FUN_001d2ee0(fp);
    }
    const char *chunk = (*(const char * *)&this->f_0c);
    if (chunk == 0) {
        return false;
    }
    hulk_intptr len = this->f_10;
    bool allocated = false;
    if (*chunk != 0x1b) {
        char *tmp = (char *)FUN_0008d6d0(len + 0x10);
        FUN_00267760(tmp, this->f_10 + 0x10, "return (%s)", (*(const char * *)&this->f_0c));
        allocated = true;
        chunk = tmp;
        const char *e = tmp;
        while (*e != 0)
            e++;
        len = e - tmp;
    }
    int rc = ((owners::Obj_1d35a0 *)mgr)->FUN_001d35a0(chunk, (hulk_intptr)(fr.buf), (hulk_intptr)len);
    if (allocated)
        FUN_0008d340((void *)chunk);
    if (rc != 3) {
        return false;
    }
    void *L = mgr->L;
    bool ok = FUN_00213160(L, -1) == 1;
    FUN_00212d80(L, -2);
    return ok;
}

