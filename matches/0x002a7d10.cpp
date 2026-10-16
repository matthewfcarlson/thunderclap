#include "gen/pure3d.h"

typedef unsigned char u8;
struct Helper_2a7d10 {
    void Decode(void* a, u8* out);
};

void pure3d::SceneGraphVisibilityAnimationController::vfunc_7() {
    u8 x;
    (*(Helper_2a7d10 * *)&this->f_40)->Decode((*(void * *)&this->f_34), &x);
    *((u8*)(*(void * *)&this->f_44) + 0x28) = x;
}
