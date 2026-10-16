// Same code shape as 0x002a7540 (propagated; names are from that function)
#include "gen/pure3d.h"

class Other_2e0a40 {
  public:
    int helper(pure3d::VertexAnimPrimGroup*);
};
extern "C" void* __cdecl allocate(int);

void* pure3d::VertexAnimPrimGroup::vfunc_4() {
    pure3d::VertexAnimPrimGroup* self = this;
    Other_2e0a40* p = (Other_2e0a40*)allocate(0x60);
    if (p)
        return (void*)(p->helper(self));
    return (void*)(0);
}
