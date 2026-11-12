// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b3de0..0x000b4280 (kind game, layer game, confidence medium), dominant class FEControllerSystem
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f30893a2 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f30893a2 {} using namespace fn_f30893a2;
namespace fn_f30893a2 { extern "C" char DAT_004060fc[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f30893a2 {
class FEControllerSystem {
  public:
    FEControllerSystem();
    virtual ~FEControllerSystem();
};
class Obj {
  public:
    virtual void Go();
};
class Source {
  public:
};
class Target {
  public:
    char pad[4];
    Obj* obj;
    void Fn(Source* src);
};
class IControllerManager_b3ed0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public IControllerManager_b3ed0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
class Ref_b3ef0 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_b3ef0 {
  public:
    char pad[4];
    Ref_b3ef0* p;
    void Clear();
};


// 0x000b3de0 FUN_000b3de0 (9 B): matches/0x000b3de0.cpp
// sym: ??0FEControllerSystem@fn_f30893a2@@QAE@XZ
FEControllerSystem::FEControllerSystem() {}


// 0x000b3e00 FUN_000b3e00 (31 B): matches/0x000b3e00.cpp
// sym: ?Fn@Target@fn_f30893a2@@QAEXPAVSource@2@@Z
void Target::Fn(Source* src) {
    if (src) {
        obj = ((Obj *)((owners::C_ae640 *)src)->FUN_000ae640(0));
        obj->Go();
    }
}

} // namespace fn_f30893a2

// 0x000b3ec0 FUN_000b3ec0 (11 B): matches/0x000b3ec0.cpp
// sym: ?FUN_000b3ec0@C_b3ec0@owners@@QAEHH@Z
hulk_intptr owners::C_b3ec0::FUN_000b3ec0(int i) {
    return m[i];
}

namespace fn_f30893a2 {

// 0x000b3ed0 FEControllerSystem::vfunc_0 (31 B): matches/0x000b3ed0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f30893a2@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004060fc;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000b3ef0 FUN_000b3ef0 (24 B): matches/0x000b3ef0.cpp
// sym: ?Clear@Owner_b3ef0@fn_f30893a2@@QAEXXZ
void Owner_b3ef0::Clear() {
    if (p) {
        p->Release();
        p = 0;
    }
}

} // namespace fn_f30893a2

// 0x000b3f10 FEControllerSystem::vfunc_1 (731 B): equivalent/0x000b3f10.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?vfunc_1@FEControllerSystem@fn_000b3f10@@UAEXHPAM@Z @d6c3fad248a6 @wb9162937f2ec
namespace fn_000b3f10 {
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 28/34, incomplete)
// FEControllerSystem::vfunc_1 @ 0x000b3f10

struct Pad_b3f10 {
    void FUN_000ada70(float *state);
};


static void accumulate(float *out, const float *s, const int &srcIdx, const int &dstIdx)
{
    int si = srcIdx;
    int di = dstIdx;
    out[di] = s[si] + out[di];
    int d2 = dstIdx;
    float v = out[d2];
    out[d2] = (v < 1.0f) ? v : 1.0f;
}

static void addClamped(float *dst, float v)
{
    *dst = v + *dst;
    float r = *dst;
    *dst = (r < 1.0f) ? r : 1.0f;
}

class FEControllerSystem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int index, float *out);
    Pad_b3f10 *pads[1];           // 0x4
};

void FEControllerSystem::vfunc_1(int index, float *out)
{
    if (index >= 1)
        return;
    float s[17];
    pads[index]->FUN_000ada70(s);
    out[0] = 0.0f; out[1] = 0.0f; out[2] = 0.0f; out[3] = 0.0f; out[4] = 0.0f;
    out[5] = 0.0f; out[6] = 0.0f; out[7] = 0.0f; out[8] = 0.0f; out[9] = 0.0f;
    accumulate(out, s, DAT_0049f31c, DAT_0049f320);
    accumulate(out, s, DAT_0049f324, DAT_0049f328);
    accumulate(out, s, DAT_0049f32c, DAT_0049f330);
    accumulate(out, s, DAT_0049f334, DAT_0049f338);
    accumulate(out, s, DAT_0049f33c, DAT_0049f340);
    accumulate(out, s, DAT_0049f344, DAT_0049f348);
    accumulate(out, s, DAT_0049f34c, DAT_0049f350);
    for (int k = 0; k < 2; k++) {
        float a = s[11 + 2 * k];
        float neg = (0.0f < -a) ? -a : 0.0f;
        addClamped(&out[0], neg);
        float pos = (0.0f < a) ? a : 0.0f;
        addClamped(&out[1], pos);
        float b = s[12 + 2 * k];
        float negb = (0.0f < -b) ? -b : 0.0f;
        addClamped(&out[3], negb);
        float posb = (0.0f < b) ? b : 0.0f;
        addClamped(&out[2], posb);
    }
}
} // namespace fn_000b3f10

