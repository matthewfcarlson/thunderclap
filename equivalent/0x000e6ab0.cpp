// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FEThingsBase::vfunc_15 @ 0x000e6ab0
struct Thing {
    void FUN_000e5440(int mode);
};


class FEThingsBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(Thing *thing);
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(Thing *thing);
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int mode);

    char pad04[0x175c - 4];
    Thing *current;        // +0x175c
    char pad1760[8];
    Thing *pending;        // +0x1768
    int mode;              // +0x176c
    char pad1770[0x17b0 - 0x1770];
    int state;             // +0x17b0
    char pad17b4[0x17f8 - 0x17b4];
    int f17f8;
};

void FEThingsBase::vfunc_15(Thing *thing) {
    if (thing == current) {
        return;
    }
    if (state == 0xf) {
        vfunc_48(7);
        return;
    }
    pending = thing;
    if (thing == 0) {
        return;
    }
    vfunc_25(thing);
    if (state > 0) {
        vfunc_48(4);
    }
    Thing *old = current;
    f17f8 = 0;
    mode = 2;
    if (old != 0) {
        old->FUN_000e5440(2);
    }
}
