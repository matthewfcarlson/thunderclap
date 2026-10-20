// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0033eb30 @ 0x0033eb30
// equiv-conv: FUN_0033ea90 esi
extern "C" void __cdecl FUN_0033ea90(void*);
extern "C" void __cdecl FUN_003390d0(void*, const char*, void*, int);
extern "C" void __cdecl FUN_00213680(void*, int, int);
extern "C" void __cdecl FUN_00213790(void*, int, const char*);
extern char DAT_0042257c;
extern void* DAT_00434e68;
extern char DAT_00435210;
int __cdecl FUN_0033eb30(void* param_1) {
    void* p = param_1;
    if (p == 0)
        FUN_0033ea90(p);
    else
        FUN_0033ea90(p);
    FUN_003390d0(p, &DAT_0042257c, &DAT_00434e68, 0);
    FUN_00213680(p, 0, 0);
    FUN_00213790(p, 0xffffd8ef, &DAT_00435210);
    return 2;
}