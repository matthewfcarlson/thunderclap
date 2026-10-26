#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
extern "C" char DAT_00429254[];
class Allocator {
  public:
    virtual void Fn();
};
void InitAllocator() {
    (*(Allocator**)&DAT_004cc200) = (Allocator*)((hulk_intptr)DAT_00429254);
}