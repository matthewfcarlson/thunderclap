#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: g_mgr_bc4d0 = DAT_004dd9cc

struct Obj_bc4d0;
extern void* g_b_bc4d0;
void __cdecl Fa(void*);
void __cdecl Release(void*);
void Fb();
Obj_bc4d0* Fc();
struct Obj_bc4d0 {
    void Fd();
};
struct Sub_bc4d0 {
    void Fe();
};
struct Mgr_bc4d0 {
    void Ff();
};
struct Dev_bc4d0 {
    void Fg(int);
};


struct Main_bc4d0 {
    char pad0[0x10];
    int state;
    char pad1[0xc];
    Dev_bc4d0* dev;
    int arg;
    char pad2[0x34];
    Sub_bc4d0* sub;
    char pad3[0xc];
    void* a[0x80];
    void* b[0x80];
    char pad4[0x1bc8 - 0x46c];
    char flag;
    void Run();
};

void Main_bc4d0::Run() {
    Fa((*(void**)&DAT_0049f3b0));
    int i;
    for (i = 0; i < 0x80; i++) {
        if (!a[i])
            break;
        Release(a[i]);
        a[i] = 0;
    }
    for (i = 0; i < 0x80; i++) {
        if (!b[i])
            break;
        Release(b[i]);
        b[i] = 0;
    }
    Fb();
    Obj_bc4d0* o = Fc();
    if (o)
        o->Fd();
    if (sub)
        sub->Fe();
    (*(Mgr_bc4d0**)&DAT_004dd9cc)->Ff();
    dev->Fg(arg);
    state = 3;
    flag = 0;
}
