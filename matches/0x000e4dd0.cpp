class Child {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual bool f7(int, int);
};
class FEContainer {
  public:
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual bool vfunc_3(int, int);
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
    virtual int vfunc_40();
    virtual int vfunc_41();
    virtual int vfunc_42();
    virtual int vfunc_43();
    virtual int vfunc_44();
    virtual int vfunc_45();
    virtual int vfunc_46();
    virtual int vfunc_47();
    virtual int vfunc_48();
    virtual int vfunc_49();
    virtual int vfunc_50();
    virtual int vfunc_51();
    virtual int vfunc_52();
    char pad[0x44];
    Child* child;
    char rest[0x808];
    int state;
};
bool FEContainer::vfunc_3(int a, int b) {
    if (state == -1 || state == b) {
        if (child != 0)
            return child->f7(a, b);
    }
    return false;
}
