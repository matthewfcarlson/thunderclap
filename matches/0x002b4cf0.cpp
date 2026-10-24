#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_0042e584[];
struct ThisCall_002a5060 {
    void Init();
};

pure3d::ShadowMeshBufferImpl* pure3d::ShadowMeshBufferImpl::FUN_002b4cf0() {
    ((ThisCall_002a5060*)(this))->Init();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return (pure3d::ShadowMeshBufferImpl*)(this);
}
