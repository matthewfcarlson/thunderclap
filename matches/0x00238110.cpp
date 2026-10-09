typedef unsigned int u32;
void* __cdecl operator_new(unsigned int);
struct Obj {
    void Ctor();
};
struct Sub1 {
    void Init1();
};
struct Sub2 {
    void Init2();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj* Create();
};
Obj* Factory::Create() {
    Obj* p = (Obj*)operator_new(0x20);
    if (p) {
        p->Ctor();
        Sub1* s1 = (Sub1*)((char*)p + 0xc);
        *(u32*)p = 0x428100;
        s1->Init1();
        Sub2* s2 = (Sub2*)((char*)p + 0x1c);
        *(u32*)((char*)p + 0x18) = 1;
        s2->Init2();
        *(u32*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}
