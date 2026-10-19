// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00360dc0 @ 0x00360dc0
// FUN_00360dc0 @ 0x00360dc0
#include "decls/data/engine/audio.h"

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
struct ThisNote_002584d0 {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
extern void __cdecl FUN_003645e0();
extern "C" int __cdecl atexit(void (__cdecl*)());

void __cdecl FUN_00360dc0()
{
    __int64 action = FUN_002672f0("SeqActionCrossFade", 0, 0);
    __int64 sequence = FUN_002672f0("Runtime_Sequence", 0, 0);
    ((ThisNote_002584d0*)(((char*)&DAT_004e74c0)))->FUN_002584d0(&sequence, &action, 28, 4);
    atexit(FUN_003645e0);
}
