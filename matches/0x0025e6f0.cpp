// Same code shape as 0x0022a5d0 (propagated; names are from that function)
#include "gen/om.h"
class MetaEntity_25e6f0 {
  public:
    virtual void f();
    MetaEntity_25e6f0* construct(void*);
};
struct MetaEntity_nv_25e6f0 {
    void InitRestPose(void*);
};
extern void* RestPoseVtable;
MetaEntity_25e6f0* MetaEntity_25e6f0::construct(void* arg) {
    ((MetaEntity_nv_25e6f0*)(((om::MetaEntity*)(this))))->InitRestPose(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}