// STATUS: equivalent (tools/equiv.py level 3: 19802 inputs, branch coverage 4/4)
// FUN_000fc060 @ 0x000fc060
// equiv-map: ??0Manager@@QAE@H@Z = 0x000ddbf0
// equiv-map: ??0Overlay@@QAE@HPAVManager@@@Z = 0x000dd940
#include "decls/data/game/global.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

class FEThings_fc060;

class ControllerPoller_fc060 {
public:
    ControllerPoller_fc060(int a, FEThings_fc060* mgr) throw();
    virtual void v0();
};

class FEThings_fc060 {
public:
    FEThings_fc060(int a) throw();
    char pad0[0x182c];
    ControllerPoller_fc060* overlay;
    void FUN_000dddc0(int a, int b);
};


void FUN_000fc060(int a1, int a2, int a3, int a4) {
    void* mem = FUN_0008d690(0x223c);
    FEThings_fc060* mgr = 0;
    if (mem)
        mgr = new (mem) FEThings_fc060(a4);
    (*(FEThings_fc060**)&DAT_004e0a60) = mgr;
    mgr->FUN_000dddc0(a1, a3);
    void* mem2 = FUN_0008d690(0x3c);
    ControllerPoller_fc060* ov = 0;
    if (mem2)
        ov = new (mem2) ControllerPoller_fc060(a2, (*(FEThings_fc060**)&DAT_004e0a60));
    (*(ControllerPoller_fc060**)&DAT_004e0a64) = ov;
    ov->v0();
    (*(FEThings_fc060**)&DAT_004e0a60)->overlay = (*(ControllerPoller_fc060**)&DAT_004e0a64);
}
