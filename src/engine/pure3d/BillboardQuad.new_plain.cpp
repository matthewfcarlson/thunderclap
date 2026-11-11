// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b87d0..0x002bd430 (kind game, layer engine, confidence high), dominant class pure3d::BillboardQuad
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f0db0e61 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0db0e61 {} using namespace fn_f0db0e61;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f0db0e61 {
extern "C" void* __cdecl FUN_0008d690(size_t);
} // namespace fn_f0db0e61
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f0db0e61 {
namespace pure3d {
struct BillboardQuadGroupBase {
    virtual void AddRef();
    virtual void Release();
    void FUN_002a3e80();
};
}
namespace pure3d {
struct BillboardQuadGroupLoader : BillboardQuadGroupBase {
    virtual void AddRef();
    virtual void Release();
};
}
namespace pure3d {
struct BillboardObjectLoader {
    virtual void AddRef_00038290();
    virtual void Release_000382a0();
    int a;
    int id;
    int b;
    int c;
    BillboardQuadGroupBase* group;
    BillboardObjectLoader();
};
}


// 0x002bc3d0 FUN_002bc3d0 (96 B): equivalent/0x002bc3d0.cpp
// sym: ??0BillboardObjectLoader@pure3d@fn_f0db0e61@@QAE@XZ @a468846bf1dd @wde1579e7bd78
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_002bc3d0 @ 0x002bc3d0
namespace pure3d {
BillboardObjectLoader::BillboardObjectLoader() : a(0), id(0x17006), b(0), c(0), group(0) {
    BillboardQuadGroupLoader* quad = (BillboardQuadGroupLoader*)FUN_0008d690(8);
    if (quad) {
        quad->FUN_002a3e80();
        new (quad) BillboardQuadGroupLoader;
        quad->AddRef();
    }
    if (group) group->Release();
    group = quad;
}
}

} // namespace fn_f0db0e61
