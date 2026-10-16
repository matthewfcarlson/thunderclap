#include "gen/pure3d.h"

class Helper_2c3140 {
  public:
    int run(pure3d::Geometry*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);

void* pure3d::Geometry::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return (void*)(((Helper_2c3140*)p)->run(this));
    return (void*)(0);
}
