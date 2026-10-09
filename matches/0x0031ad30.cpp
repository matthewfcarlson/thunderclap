namespace pure3d {
class pddiDisplay {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class pddiObject {};
class d3dDisplay : public pddiDisplay, public pddiObject {
  public:
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual unsigned int vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    char pad[0x478 - 4];
};
unsigned int d3dDisplay::vfunc_6() {
    return *(unsigned int*)((char*)this + 0x478);
}
} // namespace pure3d