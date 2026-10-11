// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 31/32, incomplete)
// FEThingsBase::vfunc_36 @ 0x000f07b0
class Param {
public:
    float FUN_000fad30();
    unsigned FUN_000faeb0();
    bool FUN_000f9e90();
};

class Args {
public:
    virtual void v0();
    virtual unsigned GetKey();
};

struct Target {
    char pad0[0x141];
    char flag141;
    char flag142;
    char pad143;
    char flag144;
    char pad145[0x14c - 0x145];
    unsigned color;
};

class FEThingsBase {
public:
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual bool FUN_000f07b0(Param *p, int b, Target *t, Args *a);
    void FUN_000eff20(Param *p, int b, Target *t, int mode);
};

bool FEThingsBase::FUN_000f07b0(Param *p, int b, Target *t, Args *a)
{
    switch (a->GetKey()) {
    case 0x800e8237:
        FUN_000eff20(p, b, t, 0);
        return true;
    case 0x04605ef2:
        FUN_000eff20(p, b, t, 1);
        return true;
    case 0xfe1d4671:
        FUN_000eff20(p, b, t, 2);
        return true;
    case 0x67b8aefc:
        FUN_000eff20(p, b, t, 3);
        return true;
    case 0xeb227e7b:
        FUN_000eff20(p, b, t, 4);
        return true;
    case 0xfb26aca4:
        t->flag144 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x700e422a:
        t->flag141 = p->FUN_000faeb0() != 0x457e63d9;
        return true;
    case 0x79bbec03:
        t->flag142 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x5d7d2382: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        int alpha = 0xff;
        if (p->FUN_000f9e90())
            alpha = (int)p->FUN_000fad30();
        t->color = (((alpha << 8 | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    }
    return false;
}
