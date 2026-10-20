#include "compat/ptr.h"
#include "gen/choreo2.h"

extern "C" char DAT_004273c4[];
typedef unsigned int u32_227650;
void* __cdecl alloc_obj(unsigned int);
class Helper_227650 {
  public:
    void a(choreo2::LocomotionStrafeDriver*);
    void b(choreo2::LocomotionStrafeDriver*);
};

void* choreo2::LocomotionStrafeDriver::vfunc_5() {
    void* p = alloc_obj(0x1330);
    if (p) {
        ((Helper_227650*)p)->a(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004273c4);
        ((Helper_227650*)p)->b(this);
        return (void*)(p);
    }
    return (void*)(0);
}
