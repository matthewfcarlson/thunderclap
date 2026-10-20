#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042e914[];
typedef unsigned int size_t;
typedef unsigned int u32_2bdf50;
void* __cdecl alloc(size_t);
namespace pure3d {

class Builder_2bdf50 {
  public:
    void init(pure3d::SpriteObject*);
};

} // namespace pure3d
void* pure3d::SpriteObject::vfunc_4() {
    pure3d::SpriteObject* p = (pure3d::SpriteObject*)alloc(0x58);
    if (p) {
        ((Builder_2bdf50*)p)->init(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042e914);
        return (void*)(p);
    }
    return (void*)(0);
}
