// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 25/26, incomplete)
// FUN_000f0950 @ 0x000f0950
// equiv-map: ?FUN_000f0950@FEThingsBase@@QAEXPAVParam@@HPAVEntity@@PAVArgs@@@Z = 0x000f0950
extern int __cdecl FUN_0034483c();
extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned n);

class Args {
public:
    virtual void v0();
    virtual int GetType();
};

class Param {
public:
    float FUN_000fad30();
    char *FUN_000fad90();
    char FUN_000f9e90();
    char FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
    int FUN_000fb110();
};

class Obj_f0950 {
public:
    char pad0[0xab8];
    char flag;
    void FUN_000e4610(char *s);
};

class FEThingsBase;

class Entity {
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
    virtual void v16(char *s);
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
    virtual int v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(char *s);
    char pad4[0x854 - 4];
    int result;
    char pad858[0x9dc - 0x858];
    char field9dc[4];
    void FUN_000e55e0(Obj_f0950 *o);
};

class Dummy {};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, Entity *, Args *);
        int mC;
        Entity *mD;
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
    virtual void v35();
    virtual void v36();
    virtual char v37(Param *p, Entity *d, Args *a);
    virtual void v38();
    virtual char v39(Param *p, char *q, Args *a);
    char pad[0x2105 - 4];
    char buf2105[1];

    Obj_f0950 *FUN_000efca0(char *s, int v);
    void FUN_000e8070(Param *p, int z, Obj_f0950 *o, int v);
    void FUN_000f0950(Param *param, int c, Entity *d, Args *args);
};

void FEThingsBase::FUN_000f0950(Param *param, int c, Entity *d, Args *args)
{
    int type = args->GetType();
    if (type == 0x16082730) {
        char *name = param->FUN_000fad90();
        Obj_f0950 *o = FUN_000efca0(name, d->v35());
        o->FUN_000e4610(buf2105);
        if (param->FUN_000f9e90()) {
            if (memcmp(param->FUN_000fad90(), "hide", 5) == 0)
                o->flag = 0;
        }
        d->FUN_000e55e0(o);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e8070(param, 0, o, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    }
    if (type == 0x887d4b38) {
        d->v16(param->FUN_000fad90());
        return;
    }
    if (type == 0x16b6f665) {
        d->v53(param->FUN_000fad90());
        return;
    }
    if (type == 0x3752e43c) {
        d->result = (int)param->FUN_000fad30();
        return;
    }
    if (v39(param, d->field9dc, args))
        return;
    if (v37(param, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f0950;
    f.mC = c;
    f.mD = d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
