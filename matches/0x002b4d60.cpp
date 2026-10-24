#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_0042e584[];
extern void __fastcall Init(void*);

pure3d::ShadowMeshBufferImpl* pure3d::ShadowMeshBufferImpl::FUN_002b4d60(int arg) {
    Init(this);
    *(void**)this = (void*)((hulk_intptr)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return (pure3d::ShadowMeshBufferImpl*)(this);
}
