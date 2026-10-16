// STATUS: equivalent (tools/equiv.py level 3: 316 inputs, branch coverage 30/30)
// FUN_00203e90 @ 0x00203e90
#include "decls/data/engine/content.h"

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);

class Handle_203e90 {
public:
    virtual void v0();
    bool FUN_00266750();
    int FUN_00266700();
};

struct Request {
    char name[0x100];
    int f100;
    int f104;
    int f108;
    char f10c;
    char pad10d[3];
};

struct Mgr_203e90 {
    char pad00[4];
    int limit;
    void FUN_00265810(Request* r, Handle_203e90** out);
    int FUN_00264870();
    void FUN_00264860(int v);
};

struct Target_203e90 {
    void FUN_00266220(int v);
};

struct Item_203e90 {
    void FUN_000bd1b0(int v);
};

struct Holder_203e90 {
    char pad00[0x20];
    Item_203e90* item;
    Item_203e90* FUN_00086280();
};

struct Actor_203e90 {
    char pad00[4];
    char f04;
    char pad05[0x21];
    short f26;
    char pad28[0x10];
    Target_203e90* f38;
};

int FUN_00266da0(int v);
unsigned int FUN_00267f80();
void FUN_00087990();
extern unsigned int DAT_004d9968;

class Owner_203e90 {
public:
    char pad000[0x588];
    Holder_203e90* f588;
    char pad58c[0xaf5 - 0x58c];
    char fAF5;
    char padAF6[6];
    unsigned int fAFC;

    Handle_203e90* Run(const char* name, bool a2, bool a3, Actor_203e90* actor, Target_203e90* target, int a6, int a7);
};

Handle_203e90* Owner_203e90::Run(const char* name, bool a2, bool a3, Actor_203e90* actor, Target_203e90* target, int a6, int a7)
{
    unsigned int cookie = DAT_004d9968;
    struct Frame {
        Handle_203e90* out;
        int saved;
        int prev;
        Request req;
    } f;
    f.prev = FUN_00266da0(0xb);
    if (actor)
        actor->f04 = 1;
    f.req.f108 = a7;
    f.out = 0;
    f.req.name[0] = 0;
    f.req.f100 = 0;
    f.req.f104 = 0;
    f.req.f10c = 0;
    if (name)
        strncpy(f.req.name, name, 0xff);
    f.req.f104 = a6;
    f.req.f10c = 0;
    if (actor)
        f.req.f108 = actor->f26;
    (*(Mgr_203e90**)&DAT_00527c58)->FUN_00265810(&f.req, &f.out);
    if (!a2) {
        Item_203e90* item = f588->FUN_00086280();
        if (a3 && item && !fAF5)
            item->FUN_000bd1b0(0);
        f.saved = (*(Mgr_203e90**)&DAT_00527c58)->FUN_00264870();
        (*(Mgr_203e90**)&DAT_00527c58)->FUN_00264860(250000);
        while (!f.out->FUN_00266750()) {
            if (item) {
                if ((a3 && !fAF5) || (fAFC != 0 && FUN_00267f80() - fAFC > 3000))
                    item->FUN_000bd1b0(0);
            }
            FUN_00087990();
        }
        (*(Mgr_203e90**)&DAT_00527c58)->FUN_00264860(f.saved);
        int n = f.out->FUN_00266700();
        Target_203e90* t = actor ? actor->f38 : target;
        t->FUN_00266220(n);
    }
    FUN_00266da0(f.prev);
    Handle_203e90* result = f.out;
    __security_check_cookie(cookie);
    return result;
}
