#include "compat/ptr.h"
struct AnimationFrameController {
    void Init();
    unsigned int vptr;
    char pad4[0xc];
    unsigned char field10;
    char pad11[7];
    float field18;
    AnimationFrameController();
};
extern unsigned int vtable_284af0;
AnimationFrameController::AnimationFrameController() {
    Init();
    field10 = 0;
    vptr = (hulk_uintptr)&vtable_284af0;
    field18 = 1.0f;
}
