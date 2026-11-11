// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ac2c0..0x000ac610 (kind game, layer game, confidence high), dominant class CNISCamera
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f5bd0829 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5bd0829 {} using namespace fn_f5bd0829;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5bd0829 {
class Lens {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int Mode();
    char pad04[0x10 - 4];
    float fov;
};
class CGameCamera {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetMode(int mode);
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34();
    virtual void vfunc_35(int a, int b, int c, int d);
};
class CNISCamera : public CGameCamera {
public:
    virtual void vfunc_35(int a, int b, int c, int d);
    char pad04[0xf1 - 4 - 0x0];
    unsigned char locked;
    char padf2[0x170 - 0xf2];
    Lens *lens;
    void FUN_000a9090(float fov);
};


// 0x000ac420 CNISCamera::vfunc_35 (117 B): matches/0x000ac420.cpp
// sym: ?vfunc_35@CNISCamera@fn_f5bd0829@@UAEXHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 4/4)
// CNISCamera::vfunc_35 @ 0x000ac420
void CNISCamera::vfunc_35(int a, int b, int c, int d)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (!locked && lens != 0) {
        SetMode(lens->Mode());
        FUN_000a9090(lens->fov * 57.2957764f);
        CGameCamera::vfunc_35(a, b, c, d);
    }
}

} // namespace fn_f5bd0829
