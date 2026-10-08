namespace pure3d {
class d3dDisplay {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual unsigned int vfunc_7();
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
    char pad[0x47c - 4];
    unsigned int field;
};
unsigned int d3dDisplay::vfunc_7() { return field; }
}