// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0026e9e0 @ 0x0026e9e0
struct Obj { virtual void FUN_0026e9e0_slot0(); };
extern Obj* DAT_005283b0;
extern int DAT_004cdbb0;
extern "C" void* __cdecl FUN_00266e00(int, int);
struct Created { void* FUN_0026e2a0(int, int); };
void __cdecl target(Obj** result, int value, int other) {
    if (DAT_005283b0) {
        DAT_005283b0->FUN_0026e9e0_slot0();
        *result = DAT_005283b0;
        return;
    }
    DAT_004cdbb0 = value;
    Created* created = (Created*)FUN_00266e00(value, 0x1d8);
    if (created) DAT_005283b0 = (Obj*)created->FUN_0026e2a0(value, other);
    else DAT_005283b0 = 0;
    *result = DAT_005283b0;
}