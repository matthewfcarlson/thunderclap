#include "gen/pure3d.h"

class Allocated_29a170 {
  public:
    int method(pure3d::CompositeDrawable*);
};
extern Allocated_29a170* alloc(int);

void* pure3d::CompositeDrawable::vfunc_4() {
    Allocated_29a170* p = alloc(0x58);
    if (p)
        return (void*)(p->method(this));
    return (void*)(0);
}
