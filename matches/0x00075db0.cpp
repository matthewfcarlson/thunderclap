#include "compat/ptr.h"
extern "C" char DAT_003fbef4[];
namespace fight {
class TrackFactory {};
} // namespace fight
namespace pure3d {
class Entity {};
} // namespace pure3d
namespace content {
class LoadObject {};
} // namespace content
namespace core {
class IRefCount {};
} // namespace core

class TrackFactoryTemplate_CCameraHintTrack : public fight::TrackFactory,
                                              public pure3d::Entity,
                                              public content::LoadObject,
                                              public core::IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    void* vfunc_5();
};

extern void* AllocFunc(unsigned int);

struct InternalHelper {
    void CallFunc();
};

void* TrackFactoryTemplate_CCameraHintTrack::vfunc_5() {
    void* ptr = AllocFunc(0x18);
    if (ptr != 0) {
        static_cast<InternalHelper*>(ptr)->CallFunc();
        *(hulk_uintptr*)ptr = ((hulk_intptr)DAT_003fbef4);
        ((unsigned int*)ptr)[3] = 0;
        ((float*)ptr)[4] = -1.0f;
        ((unsigned int*)ptr)[5] = 0;
        ((unsigned int*)ptr)[2] = 1;
        return ptr;
    }
    return 0;
}