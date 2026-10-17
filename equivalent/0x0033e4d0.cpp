// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e4d0 @ 0x0033e4d0
// equiv-conv: FUN_0033e4d0 esi
extern "C" void __cdecl FUN_002135a0(void *, int, const char *);
extern "C" const char * __cdecl FUN_00213190(void *, int);
extern "C" void __cdecl FUN_00212d80(void *, int);
const char * FUN_0033e4d0(void *context)
{
    FUN_002135a0(context, -10001, "LUA_PATH");
    const char *path = FUN_00213190(context, -1);
    FUN_00212d80(context, -2);
    return path ? path : "?;?.lua";
}