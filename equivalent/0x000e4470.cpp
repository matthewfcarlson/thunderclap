// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_49 @ 0x000e4470
extern "C" char *strchr(const char *s, int c);

struct Arg {
    int FUN_0022b980();
};

struct Table {
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Thing {
    char pad0[8];
    Table *table;           // 0x8
    int FUN_00284860(int index, int zero, Arg *arg);
};

class Child {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Thing *GetThing();      // slot 11
};

union Hash {
    unsigned __int64 q;
    unsigned int w[2];
};
Hash FUN_0027b020(const char *s);

class FEContainer {
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
    virtual void vfunc_48();
    virtual int vfunc_49(const char *name, Arg *arg);

    char pad4[0x28 - 4];
    Child *children[8];     // 0x28
};

int FEContainer::vfunc_49(const char *name, Arg *arg)
{
    char *dot = strchr(name, '.');
    if (dot != 0)
        return (int)dot;

    Hash id;
    id.q = FUN_0027b020(name).q;
    for (int i = 0; i < 8; i++) {
        if (children[i] == 0)
            break;
        int index = children[i]->GetThing()->table->FUN_0027b200(id.w[0], id.w[1]);
        if (index != 0xffff)
            return children[i]->GetThing()->FUN_00284860(index, 0, arg);
    }
    return arg->FUN_0022b980();
}
