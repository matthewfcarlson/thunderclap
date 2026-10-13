// STATUS: equivalent (tools/equiv.py level 3: 316 inputs, branch coverage 30/30)
// FUN_00203e90 @ 0x00203e90
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);

class Handle {
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

struct Mgr {
    char pad00[4];
    int limit;
    void FUN_00265810(Request* r, Handle** out);
    int FUN_00264870();
    void FUN_00264860(int v);
};

struct Target {
    void FUN_00266220(int v);
};

struct Item {
    void FUN_000bd1b0(int v);
};

struct Holder {
    char pad00[0x20];
    Item* item;
    Item* FUN_00086280();
};

struct Actor {
    char pad00[4];
    char f04;
    char pad05[0x21];
    short f26;
    char pad28[0x10];
    Target* f38;
};

int FUN_00266da0(int v);
unsigned int FUN_00267f80();
void FUN_00087990();
extern unsigned int DAT_004d9968;
extern Mgr* DAT_00527c58;

class Owner {
public:
    char pad000[0x588];
    Holder* f588;
    char pad58c[0xaf5 - 0x58c];
    char fAF5;
    char padAF6[6];
    unsigned int fAFC;

    Handle* Run(const char* name, bool a2, bool a3, Actor* actor, Target* target, int a6, int a7);
};

Handle* Owner::Run(const char* name, bool a2, bool a3, Actor* actor, Target* target, int a6, int a7)
{
    unsigned int cookie = DAT_004d9968;
    struct Frame {
        Handle* out;
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
    DAT_00527c58->FUN_00265810(&f.req, &f.out);
    if (!a2) {
        Item* item = f588->FUN_00086280();
        if (a3 && item && !fAF5)
            item->FUN_000bd1b0(0);
        f.saved = DAT_00527c58->FUN_00264870();
        DAT_00527c58->FUN_00264860(250000);
        while (!f.out->FUN_00266750()) {
            if (item) {
                if ((a3 && !fAF5) || (fAFC != 0 && FUN_00267f80() - fAFC > 3000))
                    item->FUN_000bd1b0(0);
            }
            FUN_00087990();
        }
        DAT_00527c58->FUN_00264860(f.saved);
        int n = f.out->FUN_00266700();
        Target* t = actor ? actor->f38 : target;
        t->FUN_00266220(n);
    }
    FUN_00266da0(f.prev);
    Handle* result = f.out;
    __security_check_cookie(cookie);
    return result;
}
