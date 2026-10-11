extern "C" char DAT_00431d1c[];
typedef unsigned int u32;
extern void* alloc(unsigned int);
struct Obj {
    void init();
};
struct HairclubPhysicsObject {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void* f28(unsigned int);
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    void build(void*, unsigned int);
    char pad[0x20];
};
void* HairclubPhysicsObject::f28(unsigned int arg) {
    void* q = alloc(0x200);
    void* p;
    if (q) {
        p = q;
        ((Obj*)p)->init();
        *(u32*)p = ((int)DAT_00431d1c);
        *(u32*)((char*)p + 0x1f8) = 0;
        *(u32*)((char*)p + 0x24) = 2;
    } else
        p = 0;
    build(p, arg);
    *(u32*)((char*)p + 0x24) = *(u32*)((char*)this + 0x24);
    return p;
}