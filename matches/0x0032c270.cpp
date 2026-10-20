#include "compat/ptr.h"
extern "C" char DAT_00433a04[];
class Base_32c270 {
  public:
    virtual void f();
    virtual void Release();
};
class Obj_32c270 {
  public:
    virtual void f();
    char pad[0x7c];
    Base_32c270* a;
    Base_32c270* b;
    void Run();
    void Tail();
};
void Obj_32c270::Run() {
    Base_32c270* p = a;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433a04);
    if (p)
        p->Release();
    p = b;
    if (p)
        p->Release();
    Tail();
}
