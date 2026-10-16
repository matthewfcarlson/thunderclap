#include "decls/data/engine/pure3d.h"

class Base_2a30a0 {
  public:
    Base_2a30a0();
};
void* Alloc(unsigned int);
class Manager_2a30a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Call(unsigned int, int);
};
class Obj_2a30a0 {
  public:
    virtual void Init();
    char pad[12];
    Manager_2a30a0* manager;
};
Obj_2a30a0* __fastcall Construct(void*);
class Target_2a30a0 : public Base_2a30a0 {
  public:
    Target_2a30a0();
    Obj_2a30a0* mObj;
};
Target_2a30a0::Target_2a30a0() {
    void* p = Alloc(0x20);
    Obj_2a30a0* o;
    if (p)
        o = Construct(p);
    else
        o = 0;
    mObj = o;
    mObj->Init();
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(((int)((char*)((char*)&DAT_0052cbb0 + 97692))), 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x444d4853, 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x54535441, 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x444d4c42, 4);
    }
}
