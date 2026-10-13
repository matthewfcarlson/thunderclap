struct ResetObject {
    void FUN_000363d0();
};
struct ContextChild {
    char pad[0x124];
    ResetObject* reset;
};
struct Context {
    char pad[0x20];
    ContextChild* child;
};
extern Context* DAT_004dd700;
extern unsigned char DAT_004e222c, DAT_004e2518;
struct Panel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    char pad[0xbbc];
    unsigned char enabled;
    void FUN_000e5440(int);
};
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
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int);
    char pad[0x1758];
    Panel* panel;
    char pad2[8];
    unsigned selected;
    int mode;
    unsigned entries[16];
    int index;
    char pad3[0x44];
    int changed;
    char pad4[0x908];
    unsigned char allowed;
};
void FEThingsBase::vfunc_21() {
    if (index < 0 || (!allowed && index == 0) || (panel && !panel->enabled)) {
        vfunc_48(7);
        return;
    }
    vfunc_48(1);
    --index;
    selected = index >= 0 ? entries[index] : 0;
    changed = 1;
    mode = 2;
    if (panel) {
        panel->v15();
        panel->FUN_000e5440(mode);
    }
    Context* context = DAT_004dd700;
    DAT_004e222c = 1;
    if (context->child && context->child->reset && DAT_004e2518) {
        DAT_004e2518 = 0;
        context->child->reset->FUN_000363d0();
    }
}