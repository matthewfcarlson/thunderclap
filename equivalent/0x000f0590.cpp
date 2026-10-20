// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 22/22)
// FEThingsBase::vfunc_34 @ 0x000f0590
class Param {
public:
    float FUN_000fad30();
    __int64 FUN_000faeb0();
    bool FUN_000f9e90();
};

class Args_f0590 {
public:
    virtual void v0();
    virtual unsigned GetKey();
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
    virtual bool vfunc_34(Param *p, Args_f0590 *a, int c);
    char pad04[0x1850 - 4];
    unsigned color;
    void FUN_000e0360(float x, float y, float z);
    int FUN_000e7ec0(__int64 id, Param *p);
    int FUN_000e7f10(__int64 id, Param *p);
    void FUN_000e0300(float f, int a, int b);
    void FUN_000e03c0(float x, float y, int a, int b, int c);
    void FUN_000e7d90(Param *p, int c);
    void FUN_000e7c30(Param *p, int c);
    void FUN_000e7cd0(Param *p, int c);
    void FUN_000e7b90(Param *p, int c);
};

bool FEThingsBase::vfunc_34(Param *p, Args_f0590 *a, int c)
{
    switch (a->GetKey()) {
    case 0x9cf1366a: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        float z = p->FUN_000fad30();
        FUN_000e0360(x, y, z);
        return true;
    }
    case 0x81467d1e: {
        float f = p->FUN_000fad30();
        int ra = FUN_000e7ec0(p->FUN_000faeb0(), p);
        int rb = 2;
        if (p->FUN_000f9e90())
            rb = FUN_000e7f10(p->FUN_000faeb0(), p);
        FUN_000e0300(f, ra, rb);
        return true;
    }
    case 0xdc18a191: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        FUN_000e03c0(x, y, c1, c2, c3);
        return true;
    }
    case 0x0d2b530a: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        color = (((0xffffff00u | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    case 0x257960fb:
        FUN_000e7d90(p, c);
        return true;
    case 0x3d3d4c3b:
        FUN_000e7c30(p, c);
        return true;
    case 0x3e24edbf:
        FUN_000e7cd0(p, c);
        return true;
    case 0x5772e4d0:
        FUN_000e7b90(p, c);
        return true;
    }
    return false;
}
