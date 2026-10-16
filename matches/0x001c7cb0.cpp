// Same code shape as 0x001c5790 (propagated; names are from that function)
#include "gen/Render.h"

class StoreBase_1c7cb0 {
  public:
    virtual void x();
    char pad[0x118];
    unsigned char flag;
};
class ObjectTemplate_1c7cb0 {
  public:
    void f();
};
void __cdecl ReleaseTemplate(ObjectTemplate_1c7cb0*);

template <> void Render::Store<Render::Room>::vfunc_2(void* __p0) { ObjectTemplate_1c7cb0 * p = (ObjectTemplate_1c7cb0 *)__p0;

    if (this->f_11c && p) {
        p->f();
        ReleaseTemplate(p);
    }
}
