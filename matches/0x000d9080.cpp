#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: kZero_d9080 = DAT_003f335c

struct Mgr_d9080 {
    char pad[0x1bc8];
    char flag;
};
struct Mgr2_d9080 {
    Mgr_d9080* Get();
};
extern Mgr2_d9080* g_mgr_d9080;

struct Menu_d9080 {
    void Show(const char* a, const char* b, const char* f1, const char* f2, const char* ok, int n,
              const char* f3, const char* f4);
};

struct FEMemCardControl_d9080 {
    char pad[0x21c];
    int v21c;
    char pad2[0x3b0 - 0x220];
    char f3b0;
    char pad3[0x3eb - 0x3b1];
    char f3eb;
    Menu_d9080* GetMenu();
    void Run(int a, int b);
};


void FEMemCardControl_d9080::Run(int a, int b) {
    Menu_d9080* m = GetMenu();
    const char* s;
    if (!f3eb) {
        Mgr_d9080* g = g_mgr_d9080->Get();
        if (g->flag)
            s = DAT_004a0ce4;
        else
            s = DAT_004a0ce0;
    } else {
        s = DAT_004a0ce8;
    }
    m->Show(s, DAT_004a0c90, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c), DAT_00408ee8, 2, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c));
    f3b0 = 1;
    v21c = 0;
}
