// Same code shape as 0x0022a5d0 (propagated; names are from that function)
#include "gen/pure3d.h"
class ShadowMeshBuffer_2df0b0 {
  public:
    virtual void f();
    ShadowMeshBuffer_2df0b0* construct(void*);
};
struct ShadowSkin_nv_2df0b0 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
ShadowMeshBuffer_2df0b0* ShadowMeshBuffer_2df0b0::construct(void* arg) {
    ((ShadowSkin_nv_2df0b0*)(((pure3d::ShadowSkin*)(((pure3d::ShadowSkin*)(this))))))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}