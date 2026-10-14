// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00233c50 @ 0x00233c50
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;
extern unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);

extern const char *DAT_004ca26c;
extern const char *DAT_004ca270;
extern const char *DAT_004ca278;
extern const char *DAT_004ca29c;

struct Branch;
struct Writer_233c50 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(unsigned __int64 key, char *buf, int size);
    virtual void v9();
    virtual void v10(unsigned __int64 key, int *out);
    virtual void v11(unsigned __int64 key, char *out);
    void FUN_00232c40(unsigned __int64 key, Branch *b);
};

extern void __cdecl FUN_00232cc0(Writer_233c50 *w, const char *msg);

struct Holder_233c50 {
    int FUN_00233b30(int index, Branch *b);
};
struct Finder_233c50 {
    Holder_233c50 *FUN_00233580(char *name);
};
struct Obj28_233c50 {
    char pad0[0x5c];
    Finder_233c50 *finder;
};
struct Ctx_233c50 {
    char pad0[0x28];
    Obj28_233c50 *p28;
};

struct Frame_233c50 {
    char pad[3];
    char flag;
    int count;
    char buf[0x400];
    int gap;
    unsigned int cookie;
};

struct Branch {
    char pad0[0x14];
    Holder_233c50 *holder;
    char FUN_00233c50(Ctx_233c50 *ctx, Writer_233c50 *w, int index);
};

char Branch::FUN_00233c50(Ctx_233c50 *ctx, Writer_233c50 *w, int index)
{
    Frame_233c50 f;
    f.cookie = DAT_004d9968;
    w->FUN_00232c40(FUN_002672f0(DAT_004ca26c, 0, 0), this);
    f.buf[0] = 0;
    for (int i = 1; i < 0x400; i++)
        f.buf[i] = 0;
    w->v8(FUN_002672f0(DAT_004ca270, 0, 0), f.buf, 0x400);
    f.count = 0;
    w->v10(FUN_002672f0(DAT_004ca278, 0, 0), &f.count);
    char ok = w->v3();
    if (!ok) {
        f.flag = ok;
        w->v11(FUN_002672f0(DAT_004ca29c, 0, 0), &f.flag);
    }
    Holder_233c50 *h = holder;
    if (f.buf[0] != 0 && ctx->p28 != 0) {
        Holder_233c50 *found = ctx->p28->finder->FUN_00233580(f.buf);
        if (found != 0)
            h = found;
    }
    char result = 0;
    if (h != 0) {
        result = h->FUN_00233b30(index, this) >= 0;
        if (!result)
            FUN_00232cc0(w, "Failed to insert branch into parent branch.");
    }
    __security_check_cookie(f.cookie);
    return result;
}
