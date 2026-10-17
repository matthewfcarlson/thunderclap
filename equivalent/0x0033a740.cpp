// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033a740 @ 0x0033a740
extern char DAT_00434708;
extern void __cdecl FUN_00213550(void *, const void *);
extern void __cdecl FUN_00213600(void *, int);
extern int __cdecl FUN_00212f00(void *, int);
extern void __cdecl FUN_00212d80(void *, int);
extern void __cdecl FUN_00213680(void *, int, int);
extern void __cdecl FUN_00212ed0(void *, int);
extern void __cdecl FUN_00213800(void *, int);
// equiv-conv: FUN_0033a740 esi
void FUN_0033a740(void *context)
{
    FUN_00213550(context, &DAT_00434708);
    FUN_00213600(context, -10000);
    if (FUN_00212f00(context, -1) != 5) {
        FUN_00212d80(context, -2);
        FUN_00213680(context, 0, 0);
        FUN_00213550(context, &DAT_00434708);
        FUN_00212ed0(context, -2);
        FUN_00213800(context, -10000);
    }
}