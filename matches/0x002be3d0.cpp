#include "gen/pure3d.h"

class Other_2be3d0 {
  public:
    void call(void*);
};

void pure3d::Sprite::vfunc_11(void* __p0) { Other_2be3d0 * obj = (Other_2be3d0 *)__p0;

    obj->call((char*)this + 0x78);
}
