#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

extern int __cdecl FUN_00212d70(int);
extern int __cdecl FUN_002135a0(int, int, const char*);
extern void __cdecl FUN_00212ed0(int, int);
extern void __cdecl FUN_002139a0(int, int, int);
extern int __cdecl FUN_00213190(int, int);
extern void __cdecl FUN_00347eed(const void*, const void*);
extern void __cdecl FUN_00212d80(int, int);
extern int __cdecl FUN_00338e20(int, const char*);
extern const char tostring[];
extern const char error[];
extern float zero_33d6e0;
int __cdecl target(int value) {
    int esi = value;
    int ebp = FUN_00212d70(esi);
    FUN_002135a0(esi, -10001, tostring);
    int edi = 1;
    if (ebp < edi)
        goto finish;
loop:
    FUN_00212ed0(esi, -1);
    FUN_00212ed0(esi, edi);
    FUN_002139a0(esi, 1, 1);
    int ebx = FUN_00213190(esi, -1);
    if (!ebx)
        goto failure;
    if (edi > 1)
        FUN_00347eed((void*)((int)((char*)&DAT_00434f70)), &zero_33d6e0);
    FUN_00347eed((void*)ebx, &zero_33d6e0);
    FUN_00212d80(esi, -2);
    ++edi;
    if (edi <= ebp)
        goto loop;
finish:
    FUN_00347eed((void*)((int)((char*)&DAT_00422518)), &zero_33d6e0);
    return 0;
failure:
    return FUN_00338e20(esi, error);
}