class Child {
  public:
    Child(int);
};
class Sub {
  public:
    Sub();
};
extern char VT_18eb80[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory_18eb80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
};
void* Factory_18eb80::f() {
    Child* p = (Child*)FUN_0008d690(0x20);
    if (p) {
        p->Child::Child(0);
        *(void**)p = VT_18eb80;
        ((Sub*)((char*)p + 0x10))->Sub::Sub();
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}