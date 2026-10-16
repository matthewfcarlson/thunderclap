#include "gen/Render.h"

class StoreBase_1c5790 {
  public:
    virtual void x();
    char pad[0x118];
    unsigned char flag;
};
class ObjectTemplate_1c5790 {
  public:
    void f();
};
void __cdecl ReleaseTemplate(ObjectTemplate_1c5790*);

template <> void Render::Store<Render::ObjectTemplate>::vfunc_2(void* __p0) { ObjectTemplate_1c5790 * p = (ObjectTemplate_1c5790 *)__p0;

    if (this->f_11c && p) {
        p->f();
        ReleaseTemplate(p);
    }
}
