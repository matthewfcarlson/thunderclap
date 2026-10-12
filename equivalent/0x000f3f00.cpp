// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 44/44)
// FUN_000f3f00 @ 0x000f3f00
extern char DAT_0049f4f0[];
extern char DAT_0049f4d8[];
extern int DAT_004dd9cc;
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
int __cdecl FUN_000c0d80(int a, int b);

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

struct Color {
    int value;
    Color* FUN_000115c0(int r, int g, int b, int a);
};

struct Box {
    float f0, f4, f8, fc, f10, f14;
};

struct Frame3 {
    char pad00[0x14];
    Box box;
};

class Sink {
public:
    char pad00[0x150];
    float f150;
    char pad154[4];
    int f158;
    float f15c;
    float f160;
    float f164;
    int f168;
    float f16c;
    char pad170[0x184 - 0x170];
    Vec3 vec184;
    Frame3* frame;
    char pad194[0x1ec - 0x194];
    int color;
    float f1f0;
    float f1f4;
    void FUN_000e2d60(int v);
    void FUN_000f1ab0(int v);
    void FUN_000f2a80(int v);
    void FUN_000f2b10(int v);
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

    void FUN_000f3f00(Param* param, Source* c, void* d, Args* args);
};

struct Frame {
    Vec3 pos;
    float scale;
    int pad10[2];
    FEThingsBase::ParseFunctor f;
    Box box;
};

void FEThingsBase::FUN_000f3f00(Param* param, Source* c, void* d, Args* args)
{
    Frame fr;
    Sink* sink = (Sink*)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f4d8, 0);
    int type = args->GetType();
    switch (type) {
    case 0xe10f2442:
        sink->FUN_000e2d60(param->FUN_000fad90());
        return;
    case 0xdd11a66e:
        sink->f16c = param->FUN_000fad30();
        return;
    case 0x8ebfb676: {
        int r = (int)param->FUN_000fad30();
        int g = (int)param->FUN_000fad30();
        int b = (int)param->FUN_000fad30();
        int a = 0xff;
        if (param->FUN_000f9e90())
            a = (int)param->FUN_000fad30();
        Color col;
        sink->color = col.FUN_000115c0(r, g, b, a)->value;
        return;
    }
    case 0x1babae77: {
        int v = param->FUN_000faeb0();
        if (v == 0x4ac3733b)
            sink->f158 = 2;
        else if (v == 0x5bd62f2d)
            sink->f158 = 1;
        else
            param->FUN_000fa0a0();
        return;
    }
    case 0x1f4ee86f: {
        float v = param->FUN_000fad30();
        sink->f164 = v;
        sink->f150 = v;
        return;
    }
    case 0x20a10713: {
        sink->FUN_000f1ab0(FUN_000c0d80(DAT_004dd9cc, param->FUN_000fad90()));
        if (param->FUN_000f9e90())
            sink->f1f4 = param->FUN_000fad30();
        return;
    }
    case 0x28a00121:
        sink->f168 = (int)param->FUN_000fad30();
        return;
    case 0x358b91b6:
        sink->f160 = param->FUN_000fad30();
        return;
    case 0x2c1d867d:
        sink->FUN_000f2a80(param->FUN_000fad90());
        return;
    case 0x359393a8:
        sink->f15c = param->FUN_000fad30();
        return;
    case 0x3818d345:
        sink->FUN_000f2b10(param->FUN_000fad90());
        return;
    case 0x65ba5b03: {
        int key = param->FUN_000fad90();
        c->GetVec3(key, &fr.pos);
        sink->vec184 = fr.pos;
        c->GetFloat(key, &fr.scale);
        fr.box = sink->frame->box;
        sink->f1f0 = fr.scale / (fr.box.fc - fr.box.f0);
        return;
    }
    }

    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000f3f00;
    fr.f.mC = c;
    fr.f.mD = d;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
