// STATUS: equivalent (tools/equiv.py level 3: 3121 inputs, branch coverage 84/84)
// FUN_000f4960 @ 0x000f4960
extern "C" int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp)
#if defined(__clang__)
static inline int hulk_memcmp(const void *pa, const void *pb, unsigned int n) { const unsigned char *a = (const unsigned char *)pa, *b = (const unsigned char *)pb; for (; n; --n, ++a, ++b) if (*a != *b) return *a < *b ? -1 : 1; return 0; }
#define memcmp hulk_memcmp
#endif

class Tok {
public:
    float FUN_000fad30();
    const char *FUN_000fad90();
    bool FUN_000f9e90();
    int FUN_000faeb0();
    void FUN_000fa0a0();
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    bool FUN_000f9e50();
    int FUN_000fb110();
    void FUN_000f9fb0();
};

class Key_f4960 {
public:
    virtual void v0();
    virtual int v1();
};

class NewObj_f4960;

class Obj_f4960 {
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
    virtual void v16(const char *s);
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
    char pad8c[0xa80 - 4];
    float fa80;
    float fa84;
    float fa88;
    float fa8c;
    float fa90;
    float fa94;
    char pada98[0xbc0 - 0xa98];
    bool bbc0;
    bool bbc1;
    bool bbc2;
    void FUN_000e5510(const char *s);
    void FUN_000f2db0(const char *a, const char *b);
    void FUN_000e55b0(int a, int b, int c);
    void FUN_000f2c10(const char *s);
    void FUN_000f2ee0(const char *s);
    void FUN_000e5570(float a, float b, int c, int d, int e);
    void FUN_000e5540(const char *s);
    void FUN_000f2d40(const char *s);
    void FUN_000e55e0(NewObj_f4960 *n);
};

class NewObj_f4960 {
public:
    char pad0[0xab8];
    bool bab8;
    void FUN_000e4610(char *p);
};

class FEThingsBase;
typedef void (FEThingsBase::*ParseFn)(Tok *, int, Obj_f4960 *, Key_f4960 *);

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        ParseFunctor(FEThingsBase *o, ParseFn f, Obj_f4960 *obj)
        {
            owner = o;
            fn = f;
            zero = 0;
            target = obj;
        }
        virtual void run();
        FEThingsBase *owner;
        ParseFn fn;
        int zero;
        Obj_f4960 *target;
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
    virtual bool v34(Tok *p, Key_f4960 *key, ParseFunctor *pf);
    virtual void v35();
    virtual void v36();
    virtual bool v37(Tok *p, Obj_f4960 *obj, Key_f4960 *key);
    virtual void v38();
    virtual bool v39(Tok *p, void *slot, Key_f4960 *key);
    char pad9c[0x2105 - 4];
    char f2105[0x2210 - 0x2105];
    bool (__cdecl *cb)(void *ud, FEThingsBase *self, Obj_f4960 *obj, Tok *p, Key_f4960 *key);
    void *ud;
    NewObj_f4960 *FUN_000efca0(const char *s, int v);
    void FUN_000f0950(Tok *p, int z, NewObj_f4960 *n, int x);
    void FUN_000f4960(Tok *p, int a1, Obj_f4960 *obj, Key_f4960 *key);
};

void FEThingsBase::FUN_000f4960(Tok *p, int a1, Obj_f4960 *obj, Key_f4960 *key)
{
    int hash = key->v1();
    switch (hash) {
    case 0xfa50b2bf:
        obj->fa88 = p->FUN_000fad30();
        return;
    case 0xaf1f50f1:
        obj->fa84 = p->FUN_000fad30();
        return;
    case 0x9c04d41f: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        obj->FUN_000e5510(s);
        return;
    }
    case 0x887d4b38:
        obj->v16(p->FUN_000fad90());
        return;
    case 0x92a5fe03:
        obj->fa80 = p->FUN_000fad30();
        return;
    case 0xa375e9df:
        obj->fa94 = p->FUN_000fad30();
        return;
    case 0xc4710df4:
        obj->bbc1 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    case 0xb37063b4: {
        const char *a = p->FUN_000fad90();
        if (p->FUN_000f9e90())
            obj->FUN_000f2db0(a, p->FUN_000fad90());
        else
            obj->FUN_000f2db0(a, 0);
        return;
    }
    case 0xd208ebe9: {
        int a = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int c = (int)p->FUN_000fad30();
        obj->FUN_000e55b0(a, b, c);
        return;
    }
    case 0xed3e3b75:
        obj->fa8c = p->FUN_000fad30();
        return;
    case 0x16082730: {
        const char *s = p->FUN_000fad90();
        NewObj_f4960 *n = FUN_000efca0(s, obj->v35());
        n->FUN_000e4610(f2105);
        if (p->FUN_000f9e90()) {
            const char *t = p->FUN_000fad90();
            if (memcmp(t, "hide", 5) == 0)
                n->bab8 = false;
        }
        obj->FUN_000e55e0(n);
        if (!p->FUN_000f9ef0())
            p->FUN_000fa0a0();
        p->FUN_000f9f30();
        while (p->FUN_000f9e50())
            FUN_000f0950(p, 0, n, p->FUN_000fb110());
        p->FUN_000f9fb0();
        return;
    }
    case 0x03cab25b:
        obj->fa90 = p->FUN_000fad30();
        return;
    case 0x16b6f665:
        obj->FUN_000f2c10(p->FUN_000fad90());
        return;
    case 0x2040515c:
        obj->FUN_000f2ee0(p->FUN_000fad90());
        return;
    case 0x329543ac: {
        float f1 = p->FUN_000fad30();
        float f2 = p->FUN_000fad30();
        int a = (int)p->FUN_000fad30();
        int b = (int)p->FUN_000fad30();
        int c = (int)p->FUN_000fad30();
        obj->FUN_000e5570(f1, f2, a, b, c);
        return;
    }
    case 0x425c8bd6: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        obj->FUN_000e5540(s);
        return;
    }
    case 0x35c3a495:
        obj->FUN_000f2d40(p->FUN_000fad90());
        return;
    case 0x6969d81b:
        obj->bbc2 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    case 0x6b6e3c3a:
        obj->bbc0 = (p->FUN_000faeb0() == 0x4dae9aac);
        return;
    default:
        break;
    }

    if (v39(p, &((char *)obj)[0x9dc], key))
        return;
    if (v37(p, obj, key))
        return;
    ParseFunctor pf(this, &FEThingsBase::FUN_000f4960, obj);
    if (v34(p, key, &pf))
        return;
    if (cb) {
        if (cb(ud, this, obj, p, key))
            return;
    }
    p->FUN_000fa0a0();
}
