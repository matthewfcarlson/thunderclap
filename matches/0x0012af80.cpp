extern "C" void _ReadWriteBarrier();
class Child {
  public:
    Child();
};
extern char VT_12af80[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory_12af80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
};
void* Factory_12af80::f() {
    Child* p = (Child*)FUN_0008d690(0x2c);
    if (p) {
        p->Child::Child();
        *(int*)((char*)p + 0xc) = 0;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x10) = -1.0f;
        *(char*)((char*)p + 0x1c) = 0;
        *(void**)p = VT_12af80;
        *(float*)((char*)p + 0x14) = 6.2831855f;
        *(float*)((char*)p + 0x18) = 100.0f;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        _ReadWriteBarrier();
        *(float*)((char*)p + 0x28) = -1.0f;
        *(int*)((char*)p + 0x8) = 1;
        return p;
    }
    return 0;
}
