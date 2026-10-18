// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// FUN_0008d6d0 @ 0x0008d6d0
// FUN_0008d6d0 @ 0x0008d6d0
#include "decls/data/game/unknown.h"

struct Storage { void FUN_0008d480(); };
void FUN_00267a50();
void __cdecl FUN_0026da80(int);
int __cdecl FUN_00266d90();
void* __cdecl FUN_00266e00(int, int);
void* __cdecl FUN_0008d6d0(int value) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(FUN_00266d90(), value);
}
