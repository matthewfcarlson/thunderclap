// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 51/52, incomplete)
// FUN_000dc230 @ 0x000dc230
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

extern unsigned __int64 DAT_004de670;
extern unsigned __int64 DAT_004de678;
extern unsigned __int64 DAT_004de680;
extern unsigned __int64 DAT_004de688;
extern unsigned __int64 DAT_004de690;
extern unsigned __int64 DAT_004de698;
extern unsigned __int64 DAT_004de6a0;
extern unsigned __int64 DAT_004de6c0;
extern unsigned __int64 DAT_004de6c8;

struct Node {
    virtual void vfunc_0();
    virtual unsigned __int64 vfunc_1();
};

struct Handle {
    virtual void vfunc_0();
};

struct Pool {
    Handle *FUN_000c6b20(const char *name);
};
extern Pool *DAT_004dd9cc;

struct Slot {
    int a, b, c;
};

class Parser {
public:
    bool FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    Node *FUN_000fb110();
    const char *FUN_000fad90();
    float FUN_000fad30();
    unsigned __int64 FUN_000faeb0();
    void FUN_000fa0a0();
    void FUN_000f9fb0();
};

class Sink {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void Store(const char *name, void *dest);
};

class Handler {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual bool Handle34(Parser *p, Node *node, int flag);
    virtual bool Handle35(Parser *p, Sink *sink, void *owner, Node *node);
    virtual bool Handle36(Parser *p, Sink *sink, void *owner, Node *node);
};

void FUN_000964a0(char *buf, int size, const char *fmt, ...);

class Config {
public:
    char pad0[0x154];
    char f154[0x24];
    Slot slots[5];
    char f1b4[0xc];
    char f1c0[0xc];
    Handle *f1cc;
    char pad1d0[0x3a8 - 0x1d0];
    char b3a8;
    char pad3a9[0x3e8 - 0x3a9];
    char b3e8;
    char pad3e9;
    char b3ea;

    bool FUN_000dc230(Parser *parser, Handler *handler, Sink *sink);
};

bool Config::FUN_000dc230(Parser *parser, Handler *handler, Sink *sink)
{
    unsigned int cookie = DAT_004d9968;
    char bufA[0x40];
    char bufC[0x40];
    char bufB[0x40];
    char bufD[0x40];

    if (parser->FUN_000f9ef0()) {
        parser->FUN_000f9f30();
        while (parser->FUN_000f9e50()) {
            Node *node = parser->FUN_000fb110();
            unsigned __int64 key = node->vfunc_1();
            if (key == DAT_004de670) {
                const char *name = parser->FUN_000fad90();
                sink->Store(name, f154);
            } else if (key == DAT_004de680) {
                b3e8 = (int)parser->FUN_000fad30() != 0;
            } else if (key == DAT_004de6c0) {
                unsigned __int64 v = parser->FUN_000faeb0();
                if (v == DAT_004de688) {
                    b3a8 = 0;
                } else if (v == DAT_004de690) {
                    b3a8 = 0;
                    b3ea = 1;
                } else {
                    b3a8 = 1;
                }
            } else if (key == DAT_004de678) {
                FUN_000964a0(bufA, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                Handle *h = DAT_004dd9cc->FUN_000c6b20(bufA);
                if (h)
                    h->vfunc_0();
                f1cc = h;
            } else if (key == DAT_004de6c8) {
                FUN_000964a0(bufB, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                sink->Store(bufB, f1b4);
            } else if (key == DAT_004de6a0) {
                FUN_000964a0(bufC, 0x40, "%s%d", parser->FUN_000fad90(), 1);
                sink->Store(bufC, f1c0);
            } else if (key == DAT_004de698) {
                const char *name = parser->FUN_000fad90();
                for (int i = 1; i <= 5; i++) {
                    FUN_000964a0(bufD, 0x40, "%s%d", name, i);
                    sink->Store(bufD, &slots[i - 1]);
                }
            } else {
                if (handler->Handle35(parser, sink, this, node))
                    continue;
                if (handler->Handle36(parser, sink, this, node))
                    continue;
                if (handler->Handle34(parser, node, 0))
                    continue;
                parser->FUN_000fa0a0();
                break;
            }
        }
        parser->FUN_000f9fb0();
    }
    __security_check_cookie(cookie);
    return true;
}
