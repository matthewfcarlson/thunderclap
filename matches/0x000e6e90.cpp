struct Child {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    void FUN_000e5440(int);
};
struct Action {
    void FUN_000363d0();
};
struct Context {
    char pad[0x124];
    Action* action;
};
struct Manager {
    char pad[0x20];
    Context* context;
};
extern Manager* DAT_004dd700;
extern unsigned char DAT_004e222c, DAT_004e2518;
struct FEThingsBase {
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
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
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void vfunc_47();
    virtual void vfunc_48(int);
    char pad0[0x175c - 4];
    Child* child;
    char pad1[8];
    int selected;
    int mode;
    int history[16];
    int index;
    char pad2[0x17f8 - 0x17b4];
    int active;
    char pad3[0x2104 - 0x17fc];
    unsigned char enabled;
};
void FEThingsBase::vfunc_22() {
    if (index < 0 || (!enabled && index == 0)) {
        vfunc_48(7);
        return;
    }
    vfunc_48(1);
    --index;
    selected = index >= 0 ? history[index] : 0;
    active = 1;
    mode = 2;
    if (child) {
        child->s15();
        child->FUN_000e5440(mode);
    }
    DAT_004e222c = 1;
    if (DAT_004dd700->context && DAT_004dd700->context->action && DAT_004e2518) {
        DAT_004e2518 = 0;
        DAT_004dd700->context->action->FUN_000363d0();
    }
}
