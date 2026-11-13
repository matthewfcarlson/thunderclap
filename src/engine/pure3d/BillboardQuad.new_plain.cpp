// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b87d0..0x002bd430 (kind game, layer engine, confidence high), dominant class pure3d::BillboardQuad
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
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
extern "C" void* __cdecl FUN_0008d690(unsigned int);
} // namespace fn_f0db0e61
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f0db0e61 {
// (x64t7) The loaders as the words their constructors write, with the game's vftables stored by address (the local
// classes' own virtuals were declared only, so natively their slots were stubs: the AddRef below reached one).
// pure3d::RenderObjectLoader's constructor 0x002a3e80 (the vftable and NonCopyable's reference count) then the
// group loader's vftable; AddRef / Release through the stored vftables (Ref_2bc3d0's slots 0 / 1).
extern "C" char DAT_0042e7b4[];   // pure3d::BillboardQuadGroupLoader's vftable
extern "C" char DAT_0042e7d4[];   // pure3d::BillboardObjectLoader's
namespace pure3d {
struct Ref_2bc3d0 {
    virtual void AddRef();
    virtual void Release();
};
HULK_REFCOUNT_PACK
struct BillboardQuadGroupLoader {
    void* vftable;
    int refs;   // pure3d::NonCopyable's reference count
    void* FUN_002a3e80();   // RenderObjectLoader's constructor (returns `this`)
};
HULK_REFCOUNT_PACK_END
}
namespace pure3d {
// (x64t8) the loader's record (decls/loaders.h HulkBillboardObjectLoader), shared with 0x00291dc0's allocation
struct BillboardObjectLoader : HulkBillboardObjectLoader {
    BillboardObjectLoader();
};
}

// 0x002bc3d0 FUN_002bc3d0 (96 B): equivalent/0x002bc3d0.cpp
// sym: ??0BillboardObjectLoader@pure3d@fn_f0db0e61@@QAE@XZ @4d06de344411 @wf232dcfcc149
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_002bc3d0 @ 0x002bc3d0
namespace pure3d {
BillboardObjectLoader::BillboardObjectLoader() {
    refs = 0;
    id = 0x17006;
    f0c = 0;
    f10 = 0;
    group = 0;
    vftable = (void*)DAT_0042e7d4;
    BillboardQuadGroupLoader* quad = (BillboardQuadGroupLoader*)FUN_0008d690(sizeof(BillboardQuadGroupLoader));
    if (quad) {
        quad->FUN_002a3e80();
        quad->vftable = (void*)DAT_0042e7b4;
        ((Ref_2bc3d0*)quad)->AddRef();
    }
    if (group) ((Ref_2bc3d0*)group)->Release();   // (the record's group is a void*)
    group = quad;
}
}

} // namespace fn_f0db0e61
