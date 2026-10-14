// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 28/28)
// FUN_000f4e90 @ 0x000f4e90
class Param {
public:
    int FUN_000fad90();
    void FUN_000fa0a0();
};

class Args_f4e90 {
public:
    virtual void v0();
    virtual int GetType();
};

class Target_f4e90 {
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
    virtual void SetA(int v);
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
    virtual void v36();
    virtual int GetA(int v);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual int GetB(int v);
    char pad04[0x988];
    int field98c;
    int field990;
    int field994;
    int field998;
    int field99c;
    int field9a0;
    void FUN_000f2f50(int v);
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, Target_f4e90 *, Args_f4e90 *);
        int mC;
        Target_f4e90 *mD;
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
    virtual char v34(Param *p, Args_f4e90 *a, ParseFunctor *f);
    virtual void v35();
    virtual void v36();
    virtual char v37(Param *p, Target_f4e90 *t, Args_f4e90 *a);
    char pad[0x2210 - 4];
    char (*callback)(int ctx, FEThingsBase *self, int zero, Param *p, Args_f4e90 *a);
    int callbackCtx;

    void FUN_000f4e90(Param *p, int unused, Target_f4e90 *t, Args_f4e90 *a);
};

void FEThingsBase::FUN_000f4e90(Param *p, int unused, Target_f4e90 *t, Args_f4e90 *a)
{
    switch (a->GetType()) {
    case 0xf98f68f8:
        {
        int v = p->FUN_000fad90();
        t->field994 = t->GetA(v);
    }
        return;
    case 0xf98f68f9:
        {
        int v = p->FUN_000fad90();
        t->field990 = t->GetA(v);
    }
        return;
    case 0x9f92b475:
        {
        int v = p->FUN_000fad90();
        t->field98c = t->GetA(v);
    }
        return;
    case 0x9f77dd3b:
        {
        int v = p->FUN_000fad90();
        t->field998 = t->GetB(v);
    }
        return;
    case 0xe016e44e:
        {
        int v = p->FUN_000fad90();
        t->field9a0 = t->GetB(v);
    }
        return;
    case 0x5b01c46b:
        {
        int v = p->FUN_000fad90();
        t->field99c = t->GetB(v);
    }
        return;
    case 0x887d4b38:
        t->SetA(p->FUN_000fad90());
        return;
    case 0x35c3a495:
        t->FUN_000f2f50(p->FUN_000fad90());
        return;
    }
    if (v37(p, t, a))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f4e90;
    f.mC = 0;
    f.mD = t;
    if (v34(p, a, &f))
        return;
    if (callback) {
        if (callback(callbackCtx, this, 0, p, a))
            return;
    }
    p->FUN_000fa0a0();
}
