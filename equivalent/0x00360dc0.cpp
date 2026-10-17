// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00360dc0 @ 0x00360dc0
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern char DAT_004e74c0;
// equiv-conv: FUN_002584d0 ecx stack stack stack stack
extern void __cdecl FUN_002584d0(void*, const __int64*, const __int64*, int, int);
extern void __cdecl FUN_003645e0();
extern "C" int __cdecl atexit(void (__cdecl*)());

void __cdecl FUN_00360dc0()
{
    __int64 action = FUN_002672f0("SeqActionCrossFade", 0, 0);
    __int64 sequence = FUN_002672f0("Runtime_Sequence", 0, 0);
    FUN_002584d0(&DAT_004e74c0, &sequence, &action, 28, 4);
    atexit(FUN_003645e0);
}