// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// pure3d::CompositeDrawable::vfunc_13 @ 0x00299010
#include "gen/pure3d.h"

class Ref_299010 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Child_299010 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(Ref_299010 *r);
};
struct Elem_299010 { int a; int b; Child_299010 *c; };
struct Impl_299010 { char pad[0x3c]; Elem_299010 *begin; Elem_299010 *end; };

void pure3d::CompositeDrawable::vfunc_13(void* __p0) { Ref_299010 * r = (Ref_299010 *)__p0;

    if (r != 0)
        r->AddRef();
    if ((*(Ref_299010 * *)&this->f_10) != 0)
        (*(Ref_299010 * *)&this->f_10)->Release();
    (*(Ref_299010 * *)&this->f_10) = r;
    unsigned int count = (unsigned char)((*(Impl_299010 * *)&this->f_44)->end - (*(Impl_299010 * *)&this->f_44)->begin);
    for (unsigned int i = 0; i < count; i++)
        (*(Impl_299010 * *)&this->f_44)->begin[i].c->v13(r);
}
