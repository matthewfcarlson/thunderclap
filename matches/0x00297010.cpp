#include "compat/ptr.h"
extern "C" char DAT_0042d1ec[];
extern "C" char DAT_0042d28c[];
class Child_297010 {
  public:
    virtual void Destroy();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual Child_297010* Get();
};
class Obj_297010 {
  public:
    int vptr;
    int x[5];
    Child_297010* c;
    Obj_297010* Build(Obj_297010*);
};
class Base_297010 {
  public:
    void Init();
};
class Name_297010 {
  public:
    void Copy(Name_297010*);
};
Obj_297010* Obj_297010::Build(Obj_297010* src) {
    ((Base_297010*)this)->Init();
    vptr = ((hulk_intptr)DAT_0042d1ec);
    x[3] = src->x[3];
    x[4] = src->x[4];
    ((Name_297010*)((char*)this + 8))->Copy((Name_297010*)((char*)src + 8));
    vptr = ((hulk_intptr)DAT_0042d28c);
    c = 0;
    if (src->c) {
        Child_297010* p = src->c->Get();
        if (p)
            p->Destroy();
        if (c)
            c->Release();
        c = p;
    }
    return this;
}