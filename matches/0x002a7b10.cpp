#include "compat/ptr.h"
extern "C" char DAT_0042db8c[];
class SceneGraphTransformAnimationController {
  public:
    unsigned int vf;
    char pad[0x10c];
    int field;
    SceneGraphTransformAnimationController* vfunc_4();
    void copy(SceneGraphTransformAnimationController*);
    void initialize(int);
};
extern "C" void* alloc(unsigned int);

SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::vfunc_4() {
    SceneGraphTransformAnimationController* p = (SceneGraphTransformAnimationController*)alloc(0x118);
    if (p) {
        p->copy(this);
        p->vf = ((hulk_intptr)DAT_0042db8c);
        p->field = 0;
        p->initialize(1);
        p->field = field;
        return p;
    }
    return 0;
}
