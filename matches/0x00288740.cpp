#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d {
class Helper_288740 {
  public:
    hulk_intptr run(pure3d::PoseAnimationController*);
};
} // namespace pure3d
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
void* pure3d::PoseAnimationController::vfunc_4() {
    pure3d::Helper_288740* p = (pure3d::Helper_288740*)thunk_FUN_0008d690(0x150);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}
