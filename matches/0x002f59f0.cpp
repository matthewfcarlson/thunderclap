typedef unsigned char u8;
typedef unsigned int u32;
extern u8 global_4d2b78;
class PhysicsObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void vfunc_13();
    char pad[0x1f0 - 4];
};
void PhysicsObject::vfunc_13() {
    *((u8*)this + 0x1f4) &= 0xfd;
    *((u32*)this + 0x75) = 0;
    *((u32*)this + 0x77) = 0;
    *((u8*)this + 0x1f0) = global_4d2b78;
}