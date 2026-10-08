namespace pure3d {
class pddiObject {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiDisplay : public pddiObject {};
class d3dDisplay : public pddiDisplay {
public:
    virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10();
    virtual void f11(); virtual unsigned int vfunc_12();
    virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    char pad[0x474 - 4];
};
unsigned int d3dDisplay::vfunc_12() { return *(unsigned int*)((char*)this + 0x474); }
}