class Child {
  public:
    Child(int);
};
class Sub {
  public:
    Sub();
};
extern char VT[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
};
void* Factory::f() {
    Child* p = (Child*)FUN_0008d690(0x20);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT;
        ((Sub*)((char*)p + 0x10))->Sub::Sub();
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}