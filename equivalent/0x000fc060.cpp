// STATUS: equivalent (tools/equiv.py level 3: 2972 inputs, branch coverage 4/4)
// FUN_000fc060 @ 0x000fc060
// equiv-map: ??0Manager@@QAE@H@Z = 0x000ddbf0
// equiv-map: ??0Overlay@@QAE@HPAVManager@@@Z = 0x000dd940
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

class Manager;

class Overlay {
public:
    Overlay(int a, Manager* mgr) throw();
    virtual void v0();
};

class Manager {
public:
    Manager(int a) throw();
    char pad0[0x182c];
    Overlay* overlay;
    void FUN_000dddc0(int a, int b);
};

extern Manager* DAT_004e0a60;
extern Overlay* DAT_004e0a64;

void FUN_000fc060(int a1, int a2, int a3, int a4) {
    void* mem = FUN_0008d690(0x223c);
    Manager* mgr = 0;
    if (mem)
        mgr = new (mem) Manager(a4);
    DAT_004e0a60 = mgr;
    mgr->FUN_000dddc0(a1, a3);
    void* mem2 = FUN_0008d690(0x3c);
    Overlay* ov = 0;
    if (mem2)
        ov = new (mem2) Overlay(a2, DAT_004e0a60);
    DAT_004e0a64 = ov;
    ov->v0();
    DAT_004e0a60->overlay = DAT_004e0a64;
}
