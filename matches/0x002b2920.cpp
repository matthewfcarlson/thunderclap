// Same code shape as 0x0029a170 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/pure3d.h"

class Allocated_2b2920 {
  public:
    hulk_intptr method(pure3d::MultiController*);
};
extern Allocated_2b2920* alloc(int);

void* pure3d::MultiController::vfunc_4() {
    Allocated_2b2920* p = alloc(0x58);
    if (p)
        return (void*)(p->method(this));
    return (void*)(0);
}
