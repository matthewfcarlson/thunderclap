// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362a20 @ 0x00362a20
// Static init of a six-entry handler table (shared callbacks; entry 4 gets its own).
typedef void (__cdecl *Handler)();

void __cdecl FUN_003337f0();
void __cdecl FUN_00333800();
void __cdecl FUN_00333820();
void __cdecl FUN_00333810();
void __cdecl FUN_0032ef00();

struct Slot {
    Handler handler;
    int a;
    int b;
    int c;
    int unused[2];                  // not written here
};

Slot DAT_004d88f0[6];

void FUN_00362a20() {
    Slot *t = DAT_004d88f0;
    t[0].handler = FUN_003337f0;
    t[1].handler = FUN_00333800;
    t[2].handler = FUN_00333820;
    t[3].handler = FUN_00333810;
    t[4].handler = FUN_0032ef00;
    for (int i = 0; i < 5; i++) {
        t[i].a = 0;
        t[i].b = 0;
        t[i].c = 0;
    }
    t[5].handler = 0;
    t[5].a = 0;
    t[5].b = 0;
    t[5].c = -1;
}
