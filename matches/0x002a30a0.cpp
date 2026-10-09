class Base {
  public:
    Base();
};
void* Alloc(unsigned int);
class Manager {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Call(unsigned int, int);
};
class Obj {
  public:
    virtual void Init();
    char pad[12];
    Manager* manager;
};
Obj* __fastcall Construct(void*);
class Target : public Base {
  public:
    Target();
    Obj* mObj;
};
Target::Target() {
    void* p = Alloc(0x20);
    Obj* o;
    if (p)
        o = Construct(p);
    else
        o = 0;
    mObj = o;
    mObj->Init();
    {
        Obj* q = mObj;
        q->manager->Call(0x54494c, 0);
    }
    {
        Obj* q = mObj;
        q->manager->Call(0x444d4853, 0);
    }
    {
        Obj* q = mObj;
        q->manager->Call(0x54535441, 0);
    }
    {
        Obj* q = mObj;
        q->manager->Call(0x444d4c42, 4);
    }
}
