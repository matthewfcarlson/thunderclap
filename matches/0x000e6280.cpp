class Child_e6280 {
  public:
    virtual int f0();
    virtual bool f1(int, int);
};
class FEThingsBase {
  public:
    virtual bool vfunc_0(int, int);
    virtual int vfunc_1();
    virtual int vfunc_2();
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
    virtual int vfunc_18();
    virtual int vfunc_19();
    virtual int vfunc_20();
    virtual int vfunc_21();
    virtual int vfunc_22();
    virtual int vfunc_23();
    virtual int vfunc_24();
    virtual int vfunc_25();
    virtual int vfunc_26();
    virtual int vfunc_27();
    virtual int vfunc_28();
    virtual int vfunc_29();
    virtual int vfunc_30();
    virtual int vfunc_31();
    virtual int vfunc_32();
    virtual int vfunc_33();
    virtual int vfunc_34();
    virtual int vfunc_35();
    virtual int vfunc_36();
    virtual int vfunc_37();
    virtual int vfunc_38();
    virtual int vfunc_39();
    char pad[0x1758];
    Child_e6280* a;
    Child_e6280* b;
    char pad2[0x2218 - 0x1764];
    Child_e6280* c;
};
bool FEThingsBase::vfunc_0(int x, int index) {
    char* p = (char*)this;
    if (p[index + 0x2100])
        return true;
    if (c)
        return c->f1(x, index);
    if (b)
        return b->f1(x, index);
    if (a)
        return a->f1(x, index);
    return false;
}