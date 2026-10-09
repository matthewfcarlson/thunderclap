typedef unsigned int u32;
typedef unsigned char u8;
void* __cdecl alloc(unsigned int);
class Condition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[8];
    int fieldC;
    u8 flag10;
    void init(int);
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition* f();
};
Condition* Factory::f() {
    Condition* p = (Condition*)alloc(0x14);
    if (p) {
        p->init(0);
        *(u32*)p = 0x41926c;
        p->fieldC = 0;
        p->flag10 = 1;
        return p;
    }
    return 0;
}