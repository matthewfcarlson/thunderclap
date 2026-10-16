#include "gen/pure3d.h"

class Obj_297130 {
  public:
    int helper(pure3d::scenegraph::Scenegraph*);
};
extern Obj_297130* alloc(int);

void* pure3d::scenegraph::Scenegraph::vfunc_4() {
    Obj_297130* p = alloc(0x48);
    if (p)
        return (void*)(p->helper(this));
    return (void*)(0);
}
