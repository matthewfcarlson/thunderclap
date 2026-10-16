#include "gen/Render.h"

class Obj_1c56d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c(int);
};

template <> void Render::Store<Render::Object>::vfunc_2(void* __p0) { void * param = (void *)__p0;

    if (this->f_11c && param)
        ((Obj_1c56d0*)param)->c(1);
}
