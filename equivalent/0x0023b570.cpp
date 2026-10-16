// STATUS: equivalent (tools/equiv.py level 3: 3050 inputs, branch coverage 27/30, incomplete)
// fight::Chunk::vfunc_9 @ 0x0023b570
#include "decls/address.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

extern const char *DAT_004ca254;
extern const char *DAT_004ca26c;
extern const char *DAT_004ca270;
extern const char *DAT_004ca274;
extern const char *DAT_004ca278;
extern const char *DAT_004ca29c;
extern unsigned __int64 DAT_004e5b18;
extern unsigned __int64 DAT_004e5b20;

namespace fight { class Chunk; }

struct Name_23b570 {
    unsigned int lo, hi;
    void FUN_0027af00();
    void FUN_0027af50();
};

struct Writer_23b570 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned __int64 key, Name_23b570 *out);
    virtual void v8(unsigned __int64 key, char *buf, int size);
    virtual void v9();
    virtual void v10(unsigned __int64 key, int *out);
    virtual void v11(unsigned __int64 key, char *out);
    virtual void v12();
    virtual char HasToken();
    virtual unsigned __int64 TokenType();
    virtual void v15();
    virtual void Begin(unsigned __int64 key);
    virtual void End();
    void FUN_00232c40(unsigned __int64 key, fight::Chunk *c);
};

extern void __cdecl FUN_00232cc0(Writer_23b570 *w, const char *msg);

struct Holder_23b570 {
    int FUN_00233050();
    int FUN_00233b30(int index, fight::Chunk *c);
    int FUN_00233160(fight::Chunk *c);
    Holder_23b570 *FUN_00233580(char *name);
};

struct Scope_23b570 {
    char pad0[0x5c];
    Holder_23b570 *holder;         // 0x5c
};

struct Registry_23b570 {
    Scope_23b570 *FUN_00232840(unsigned __int64 key);
};
extern Registry_23b570 *DAT_004e5af8;

struct ListA_23b570 {
    char pad[16];
    void FUN_00236ec0();
    void FUN_00237160(unsigned int lo, unsigned int hi, Scope_23b570 *s, Writer_23b570 *w);
};

struct Frame_23b570 {
    char pad0[7];
    char flag;              // 0x07
    int count;              // 0x08
    Name_23b570 id;                // 0x0c
    int gap;                // 0x14
    int out1;               // 0x18
    char buf[0x400];        // 0x1c
    unsigned int cookie;    // 0x41c
};

namespace fight {
class Chunk {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual char vfunc_9(void *a1, Writer_23b570 *w, int a3);
    char pad04[0x14];
    ListA_23b570 list;             // 0x18
    Scope_23b570 *scope;           // 0x28
    char FUN_002337c0(int a0, Writer_23b570 *w, int index);
};
}

char fight::Chunk::vfunc_9(void *a1, Writer_23b570 *w, int a3)
{
    Frame_23b570 f;
    f.cookie = DAT_004d9968;
    if (!w->HasToken() || w->TokenType() != DAT_004e5b18) {
        __security_check_cookie(f.cookie);
        return 0;
    }
    w->Begin(DAT_004e5b18);
    f.out1 = 0;
    w->v10(FUN_002672f0(DAT_004ca274, 0, 0), &f.out1);
    w->FUN_00232c40(FUN_002672f0(DAT_004ca26c, 0, 0), this);
    f.id.FUN_0027af00();
    w->v7(FUN_002672f0(DAT_004ca254, 0, 0), &f.id);
    if (DAT_004e5af8 != 0)
        scope = DAT_004e5af8->FUN_00232840(((unsigned __int64)f.id.hi << 32) | f.id.lo);
    else
        scope = 0;
    f.buf[0] = 0;
    for (int i = 1; i < 0x400; i++)
        f.buf[i] = 0;
    w->v8(FUN_002672f0(DAT_004ca270, 0, 0), f.buf, 0x400);
    f.count = 0;
    w->v10(FUN_002672f0(DAT_004ca278, 0, 0), &f.count);
    bool ok = false;
    if (scope != 0) {
        Holder_23b570 *h = scope->holder->FUN_00233580(f.buf);
        if (h == 0)
            h = scope->holder;
        if (h != 0) {
            int r;
            if (f.count >= 0 && f.count <= h->FUN_00233050())
                r = h->FUN_00233b30(f.count, this);
            else
                r = h->FUN_00233160(this);
            ok = r >= 0;
        }
    }
    if (!ok)
        FUN_00232cc0(w, "Failed to insert fightChunk.");
    char has = w->v3();
    if (!has) {
        f.flag = has;
        w->v11(FUN_002672f0(DAT_004ca29c, 0, 0), &f.flag);
    }
    list.FUN_00236ec0();
    if (w->HasToken() && w->TokenType() == DAT_004e5b20)
        list.FUN_00237160((unsigned int)DAT_004e5b20, (unsigned int)(DAT_004e5b20 >> 32), scope, w);
    FUN_002337c0((int)this, w, -1);
    w->End();
    f.id.FUN_0027af50();
    __security_check_cookie(f.cookie);
    return 1;
}
