// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00016d30..0x00016db0 (kind game, layer game, confidence medium), dominant class CCameraShakeAction
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f06ebc19 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f06ebc19 {} using namespace fn_f06ebc19;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f06ebc19 {
class Shake_16d30 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float GetTime();

    char pad04[0xc];
    float endTime;      // +0x10
    float amplitude;    // +0x14
    float frequency;    // +0x18
};
struct CameraManager_16d30 {
    void FUN_00099320(int mode, float remaining, float amplitude, float frequency);
};
} // namespace fn_f06ebc19
struct World {
    char pad0[8];
    CameraManager_16d30 *camera;
};
namespace fn_f06ebc19 {
class CCameraShakeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused);

    char pad04[0x1c];
    Shake_16d30 *shake;       // +0x20
};


// 0x00016d30 CCameraShakeAction::vfunc_6 (124 B): matches/0x00016d30.cpp
// sym: ?vfunc_6@CCameraShakeAction@fn_f06ebc19@@UAE_NH@Z
// CCameraShakeAction::vfunc_6 @ 0x00016d30
bool CCameraShakeAction::vfunc_6(int unused) {
    float end = shake->endTime;
    float remaining = end - shake->GetTime();
    if (!(remaining <= 0.0f)) {
        Shake_16d30 *s = shake;
        float amplitude = s->amplitude;
        if (!(amplitude <= 0.0f)) {
            float frequency = s->frequency;
            if (!(frequency <= 0.0f)) {
                DAT_004dd700->camera->FUN_00099320(1, remaining, amplitude, frequency);
            }
        }
    }
    return false;
}

} // namespace fn_f06ebc19
