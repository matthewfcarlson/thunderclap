#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern "C" hulk_intptr __cdecl GetThing() throw();
extern "C" void __cdecl Func(void*) throw();
class Entity_25a2c0 {
  public:
    Entity_25a2c0(int) throw();
    virtual void a();
    char pad[0x24];
};
struct Init0 {
    char m28[8];
};
struct Init1_25a2c0 {
    Init1_25a2c0() throw() {
        m30 = 1000;
        m34 = 1000;
    }
    int m30, m34;
};
class Mix : public Entity_25a2c0, public Init0, public Init1_25a2c0 {
  public:
    Mix() throw();
    virtual void a();
    void* p38;
    void* p3c;
    void* p40;
    void* p44;
    int m48;
};
Mix::Mix() throw() : Entity_25a2c0(GetThing()) {
    _ReadWriteBarrier();
    void** e = &p3c;
    *e = e;
    p40 = e;
    p44 = e;
    p38 = e;
    m48 = 0;
    Func(m28);
}
