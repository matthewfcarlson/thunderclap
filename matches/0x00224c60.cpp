#include "compat/ptr.h"
#include "gen/choreo2.h"

class Helper_224c60 {
  public:
    hulk_intptr run(choreo2::JointDriver*);
};
extern void* thunk_FUN_0008d690(int);

void* choreo2::JointDriver::vfunc_5() {
    Helper_224c60* p = (Helper_224c60*)thunk_FUN_0008d690(0x70);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}
