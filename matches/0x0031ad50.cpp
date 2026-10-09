class pddiObject {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
};
class pddiDisplay : public pddiObject {};
class d3dDisplay : public pddiDisplay {
  public:
    virtual int vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual int vfunc_6();
    virtual int vfunc_7();
    virtual int vfunc_8();
    virtual int vfunc_9();
    virtual int vfunc_10();
    virtual int vfunc_11();
    virtual int vfunc_12();
    virtual int vfunc_13();
    virtual int vfunc_14();
    virtual int vfunc_15();
    virtual int vfunc_16();
    virtual int vfunc_17();
    char pad[0x480 - 4];
};
int d3dDisplay::vfunc_8() {
    return *(int*)((char*)this + 0x480);
}