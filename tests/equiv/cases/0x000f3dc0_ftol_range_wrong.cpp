extern char DAT_0049f4f0[];
extern char DAT_0049f454[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

class Param {
public:
    float FUN_000fad30();
    int FUN_000fad90();
    void FUN_000fa0a0();
};

class Args {
public:
    virtual void v0();
    virtual int GetType();
};

class Sink {
public:
    char pad0[0x294];
    int slotA;
    int slotB;
    void FUN_000e4060(int v);
};

class Base {
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(int, int, int, int);
        int mC;
        int mD;
    };

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
    virtual char v34(Param *p, Args *a, ParseFunctor *f);
    virtual char v35(Param *p, int x, void *y, Args *a);
    virtual char v36(Param *p, int x, void *y, Args *a);

    void FUN_000f3940(int a, int b, int c, int d);
    void FUN_000f3dc0(Param *param, int c, void *d, Args *args);
};

void FEThingsBase::FUN_000f3dc0(Param *param, int c, void *d, Args *args)
{
    Sink *sink = (Sink *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f454, 0);
    int type = args->GetType();
    if (type == 0xe037766f) {
        int n = (int)param->FUN_000fad30();
        if (n >= 0 && n < 8)
            sink->slotA = n;
        return;
    }
    if (type == 0xe10f2442) {
        sink->FUN_000e4060(param->FUN_000fad90());
        return;
    }
    if (type == 0x745453ad) {
        int n = (int)param->FUN_000fad30();
        if (n > 0 && n < 8)
            sink->slotB = n;
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f3940;
    f.mC = c;
    f.mD = (int)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
