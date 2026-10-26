#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern void* __cdecl alloc(hulk_uintptr);
extern void* MotionBlurAction_vftable[];
class BaseAction {
  public:
    BaseAction();
    virtual void a();
    virtual void b();
    char pad[0x18];
};
class MBAction : public BaseAction {
  public:
    void* owner;
    char pad2[0x2c - 0x20 - 4 - 0];
};

hulk_intptr hulkfight::motion::MotionBlurTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    MBAction* p = (MBAction*)alloc(0x2c);
    if (p) {
        p->BaseAction::BaseAction();
        *(void* volatile*)p = MotionBlurAction_vftable;
        *(void* volatile*)&p->owner = 0;
        p->owner = (void*)this;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}
