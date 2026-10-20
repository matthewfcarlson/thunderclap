#include "compat/ptr.h"
extern int FUN_00267f80();
struct Obj_266890 {
    virtual void V();
};
struct Data_266890 {
    char c;
    char pad[0xff];
    hulk_intptr a, b, d;
    char e;
    char pad2[3];
};
class Base_266890 {
  public:
    virtual void W();
    Base_266890() { a1 = 0; }
    int a1;
};
void Base_266890::W() {}
class LoadRequest : public Base_266890 {
  public:
    virtual void W();
    LoadRequest(const Data_266890*);
    int a2;
    int a3, a4, a5, a6, a7;
    Data_266890 d;
};
void LoadRequest::W() {}
LoadRequest::LoadRequest(const Data_266890* src) {
    Data_266890* p = &d;
    p->c = 0;
    p->a = 0;
    p->b = 0;
    p->d = 0;
    p->e = 0;
    *p = *src;
    a2 = FUN_00267f80();
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    Obj_266890* o = (Obj_266890*)d.b;
    if (o)
        o->V();
}