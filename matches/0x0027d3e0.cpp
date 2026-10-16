#include "gen/pure3d.h"

class Obj_27d3e0 {
  public:
    int call(pure3d::prop::StateProp*);
};
extern void* __cdecl thunk_FUN_0008d690(int);

void* pure3d::prop::StateProp::vfunc_4() {
    void* p = thunk_FUN_0008d690(0xe8);
    if (p)
        return (void*)(((Obj_27d3e0*)p)->call(this));
    return (void*)(0);
}
