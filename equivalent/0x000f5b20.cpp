// STATUS: equivalent (tools/equiv.py level 3: 3103 inputs, branch coverage 70/70)
// FUN_000f5b20 @ 0x000f5b20
#include "compat/ptr.h"
class Param {
public:
    float FUN_000fad30();
    hulk_intptr FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    char FUN_000f9ef0();
    char FUN_000f9e50();
    int FUN_000fb110();
    void FUN_000f9f30();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
};

union ParamSlot {
    Param *p;
    float f;
};

class Args_f5b20 {
public:
    virtual void v0();
    virtual int GetType();
};

class Source;

struct Node {
    char pad[0x858];
    char name[1];
    void FUN_000e4610(const char *s);
    void FUN_000f8970(int t);
    void FUN_001bded0(int t);
};

struct Holder_f5b20 {
    void FUN_000f8df0(int name, float f, int v);
    void FUN_000f8e70(int name, int iv, int v);
};

extern "C" int __cdecl FUN_0034483c();

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(ParamSlot param, Source *c, void *d, Args_f5b20 *args);
        Source *mC;
        void *mD;
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
    virtual char v34(Param *p, Args_f5b20 *a, ParseFunctor *f);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual char v39(Param *p, char *buf, Args_f5b20 *a);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Node *v44();
    virtual Node *v45();

    int field4;
    Holder_f5b20 *field8;
    char pad0c[0x1828 - 0xc];
    int field1828;
    char pad182c[0x2078 - 0x182c];
    char buf2078[0x2104 - 0x2078];
    char flag2104;
    char str2105[1];

    Node *FUN_000efca0(int t, int f);
    Node *FUN_000e6620(int t);
    Node *FUN_000e66f0(int t);
    Node *FUN_000e67b0(int t);
    void FUN_000e8180(Param *p, int zero, Node *n, int x);
    void FUN_000f4960(Param *p, int zero, Node *n, int x);
    void FUN_000f4e90(Param *p, int zero, Node *n, int x);
    void FUN_000e7f60(Param *p, int zero, Node *n, int x);
    void FUN_000f5130(int t, int v);
    void FUN_000f50a0(int t);
    void FUN_000f52a0(int t);

    void FUN_000f5b20(ParamSlot slot, Source *c, void *d, Args_f5b20 *args);
};

struct ParseFrame {
    FEThingsBase::ParseFunctor f;
};

void FEThingsBase::FUN_000f5b20(ParamSlot slot, Source *c, void *d, Args_f5b20 *args)
{
    Param *param = slot.p;
    ParseFrame fr;
    Node *n;
    switch (args->GetType()) {
    case 0x16082730:
        {
            int t = param->FUN_000fad90();
            n = FUN_000efca0(t, field1828);
        }
        n->FUN_000e4610(str2105);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e8180(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x1126cb0c: {
        int t = param->FUN_000fad90();
        v44()->FUN_000f8970(t);
        v45()->FUN_001bded0(t);
        return;
    }
    case (int)0xb37063b4: {
        int t = param->FUN_000fad90();
        if (param->FUN_000f9e90())
            FUN_000f5130(t, param->FUN_000fad90());
        else
            FUN_000f5130(t, 0);
        return;
    }
    case 0x169d3c55:
        n = FUN_000e6620(param->FUN_000fad90());
        n->FUN_000e4610(str2105);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000f4960(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x2040515c:
        FUN_000f52a0(param->FUN_000fad90());
        return;
    case 0x35c3a495:
        FUN_000f50a0(param->FUN_000fad90());
        return;
    case 0x535a4bed: {
        n = FUN_000e66f0(param->FUN_000fad90());
        const char *s = str2105;
        char *dst = n->name;
        char ch;
        do {
            ch = *s++;
            *dst++ = ch;
        } while (ch);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000f4e90(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    }
    case 0x5d3387b7:
        n = FUN_000e67b0(param->FUN_000fad90());
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e7f60(param, 0, n, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    case 0x62deec48:
        return;
    case 0x69fb0023: {
        int name = param->FUN_000fad90();
        slot.f = param->FUN_000fad30();
        if (param->FUN_000f9e90())
            field8->FUN_000f8df0(name, slot.f, param->FUN_000fad90());
        else
            field8->FUN_000f8df0(name, slot.f, 0);
        return;
    }
    case 0x6b6e3c3a: {
        int h = param->FUN_000faeb0();
        if (h == 0x4dae9aac) {
            flag2104 = 1;
            return;
        }
        if (h == (int)0xa3c653f9) {
            flag2104 = 0;
            return;
        }
        param->FUN_000fa0a0();
        return;
    }
    case 0x739453ea: {
        int name = param->FUN_000fad90();
        slot.f = param->FUN_000fad30();
        int v = 0;
        if (param->FUN_000f9e90())
            v = param->FUN_000fad90();
        field8->FUN_000f8e70(name, (int)slot.f, v);
        return;
    }
    }
    if (v39(param, buf2078, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000f5b20;
    fr.f.mC = 0;
    fr.f.mD = 0;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
