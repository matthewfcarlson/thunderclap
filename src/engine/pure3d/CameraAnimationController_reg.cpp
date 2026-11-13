// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b2110..0x002b23c0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/loaders.h"
#include "gen/content.h"
#define TREE_TU_BEGIN namespace fn_f4e2b286 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f4e2b286 {} using namespace fn_f4e2b286;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f4e2b286 {
typedef unsigned int u32_2b2110;
typedef unsigned int u32_2b2140;
typedef unsigned int u32_2b2170;
typedef unsigned int u32_2b21a0;
typedef unsigned int u32_2b21d0;
typedef unsigned int u32_2b2200;
typedef unsigned int u32_2b2230;
typedef unsigned int u32_2b2260;
typedef unsigned int u32_2b2290;
typedef unsigned int u32_2b22c0;
typedef unsigned int u32_2b22f0;
typedef unsigned int u32_2b2320;
typedef unsigned int u32_2b2350;
typedef unsigned int u32_2b2380;
extern "C" char DAT_0042e49c[];
class MultiControllerLoader : public HulkChunkHandler {
  public:
    MultiControllerLoader();
};

} // namespace fn_f4e2b286

// 0x002b2110 content::LoadInventory::DynamicCaster<pure3d::CameraAnimationController>::vfunc_0 (30 B): matches/0x002b2110.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCameraAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::CameraAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2140 content::LoadInventory::DynamicCaster<pure3d::ExpressionAnimationController>::vfunc_0 (30 B): matches/0x002b2140.cpp
// sym: ?vfunc_0@?$DynamicCaster@VExpressionAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ExpressionAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2170 content::LoadInventory::DynamicCaster<pure3d::LightAnimationController>::vfunc_0 (30 B): matches/0x002b2170.cpp
// sym: ?vfunc_0@?$DynamicCaster@VLightAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::LightAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b21a0 content::LoadInventory::DynamicCaster<pure3d::PoseAnimationController>::vfunc_0 (30 B): matches/0x002b21a0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VPoseAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::PoseAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b21d0 content::LoadInventory::DynamicCaster<pure3d::CompDrawVisibilityAnimationController>::vfunc_0 (30 B): matches/0x002b21d0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCompDrawVisibilityAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::CompDrawVisibilityAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2200 content::LoadInventory::DynamicCaster<pure3d::SceneGraphTransformAnimationController>::vfunc_0 (30 B): matches/0x002b2200.cpp
// sym: ?vfunc_0@?$DynamicCaster@VSceneGraphTransformAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::SceneGraphTransformAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2230 content::LoadInventory::DynamicCaster<pure3d::SceneGraphVisibilityAnimationController>::vfunc_0 (30 B): matches/0x002b2230.cpp
// sym: ?vfunc_0@?$DynamicCaster@VSceneGraphVisibilityAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::SceneGraphVisibilityAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2260 content::LoadInventory::DynamicCaster<pure3d::TextureAnimationController>::vfunc_0 (30 B): matches/0x002b2260.cpp
// sym: ?vfunc_0@?$DynamicCaster@VTextureAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::TextureAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2290 content::LoadInventory::DynamicCaster<pure3d::BillboardQuadGroupAnimationController>::vfunc_0 (30 B): matches/0x002b2290.cpp
// sym: ?vfunc_0@?$DynamicCaster@VBillboardQuadGroupAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::BillboardQuadGroupAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b22c0 content::LoadInventory::DynamicCaster<pure3d::ParticleController>::vfunc_0 (30 B): matches/0x002b22c0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VParticleController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ParticleController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b22f0 content::LoadInventory::DynamicCaster<pure3d::VertexAnimController>::vfunc_0 (30 B): matches/0x002b22f0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VVertexAnimController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::VertexAnimController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2320 content::LoadInventory::DynamicCaster<pure3d::ProceduralVertexAnimController>::vfunc_0 (30 B): matches/0x002b2320.cpp
// sym: ?vfunc_0@?$DynamicCaster@VProceduralVertexAnimController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ProceduralVertexAnimController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2350 content::LoadInventory::DynamicCaster<pure3d::ShaderAnimationController>::vfunc_0 (30 B): matches/0x002b2350.cpp
// sym: ?vfunc_0@?$DynamicCaster@VShaderAnimationController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ShaderAnimationController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002b2380 content::LoadInventory::DynamicCaster<pure3d::FrameController>::vfunc_0 (30 B): matches/0x002b2380.cpp
// sym: ?vfunc_0@?$DynamicCaster@VFrameController@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::FrameController>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

namespace fn_f4e2b286 {

// 0x002b23a0 FUN_002b23a0 (27 B): matches/0x002b23a0.cpp
// sym: ??0MultiControllerLoader@fn_f4e2b286@@QAE@XZ
MultiControllerLoader::MultiControllerLoader() {
    refs = 0;
    id = 0x121202;
    f0c = 0;
    f10 = 0;
    vftable = (void*)DAT_0042e49c;
}

} // namespace fn_f4e2b286
