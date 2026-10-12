// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 24/24)
// FUN_000e7930 @ 0x000e7930
extern char DAT_0049f4f0[];
extern char DAT_004a128c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

class Param {
public:
    char FUN_000f9e90();
    char *FUN_000fad90();
    int FUN_000faeb0();
    void FUN_000fa0a0();
};

class Args {
public:
    virtual void v0();
    virtual int GetType();
};

class Sink {
public:
    void FUN_000e2f80(char *s);
    char pad0[0x1d58];
    int count;
    char pad1[0x1da8 - 0x1d5c];
    char flag;
    char names[128][64];
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, void *, Args *);
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

    void FUN_000e7930(Param *param, int c, void *d, Args *args);
    void Parse(Param *param, int c, void *d, Args *args);
};

void FEThingsBase::Parse(Param *param, int c, void *d, Args *args)
{
    Sink *sink = (Sink *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_004a128c, 0);
    int type = args->GetType();
    if (type == 0xe10f2442) {
        sink->FUN_000e2f80(param->FUN_000fad90());
        return;
    }
    if (type == 0x1babae77) {
        int kind = param->FUN_000faeb0();
        if (kind == 0x2f97d561) {
            sink->flag = 0;
        } else if (kind == 0x612213a0) {
            sink->flag = 1;
        } else {
            param->FUN_000fa0a0();
        }
        return;
    }
    if (type == 0x76744a71) {
        while (param->FUN_000f9e90()) {
            const char *s = param->FUN_000fad90();
            if (sink->count < 0x80) {
                char *dst = sink->names[sink->count];
                char ch;
                do {
                    ch = *s++;
                    *dst++ = ch;
                } while (ch != 0);
                sink->count++;
            }
        }
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000e7930;
    f.mC = c;
    f.mD = (int)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
