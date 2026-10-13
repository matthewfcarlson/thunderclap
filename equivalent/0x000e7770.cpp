// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e7770 @ 0x000e7770
extern char DAT_0049f4f0[];
extern char DAT_0049f4a4[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

class Param {
public:
    float FUN_000fad30();
    int FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
};

class Args {
public:
    virtual void v0();
    virtual int GetType();
};

struct Vec3 {
    float x, y, z;
};

class Source {
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
    virtual void GetVec3(int key, Vec3* out);
    virtual void v49();
    virtual void GetFloat(int key, float* out);
};


struct Sink {
    char pad00[0x150];
    int color150;
    char pad154[4];
    int color158;
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase* mObj;
        void (FEThingsBase::*mFn)(Param* param, Source* c, void* d, Args* args);
        Source* mC;
        void* mD;
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
    virtual char v34(Param* p, Args* a, ParseFunctor* f);
    virtual char v35(Param* p, Source* c, void* d, Args* a);
    virtual char v36(Param* p, Source* c, void* d, Args* a);

    void FUN_000e7770(Param* param, Source* c, void* d, Args* args);
};

struct Frame {
    FEThingsBase::ParseFunctor f;
};

static int ParseColor(Param *param)
{
    int r = (int)param->FUN_000fad30();
    int g = (int)param->FUN_000fad30();
    int b = (int)param->FUN_000fad30();
    int a = 0xff;
    if (param->FUN_000f9e90())
        a = (int)param->FUN_000fad30();
    return (((a << 8 | r) << 8 | g) << 8) | b;
}

void FEThingsBase::FUN_000e7770(Param* param, Source* c, void* d, Args* args)
{
    Frame fr;
    Sink* sink = (Sink*)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f4a4, 0);
    int type = args->GetType();
    if (type == 0x8ebfb676) {
        sink->color158 = ParseColor(param);
        return;
    }
    if (type == 0x1c69411d) {
        sink->color150 = ParseColor(param);
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000e7770;
    fr.f.mC = c;
    fr.f.mD = d;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
