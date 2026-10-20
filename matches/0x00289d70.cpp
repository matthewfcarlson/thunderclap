#include "compat/ptr.h"
extern "C" char DAT_0042c8c4[];
class AnimationGroup {
  public:
    int x;
    void vfunc_1();
};
struct Sub_289d70 {
    void Helper();
};
class Thing_289d70 : public AnimationGroup {
  public:
    char pad[4];
    Sub_289d70 sub;
    void Target();
};
void Thing_289d70::Target() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042c8c4);
    AnimationGroup::vfunc_1();
    sub.Helper();
}