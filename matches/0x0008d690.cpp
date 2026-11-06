#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
// data: obj = DAT_004dd780, ready = DAT_004dd778

extern "C" void _ReadWriteBarrier();
struct Storage {
    void FUN_0008d480();
};
extern "C" void __cdecl FUN_00267a50();
extern "C" void __cdecl FUN_0026da80(int);
extern "C" int __cdecl FUN_00266d90();
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
extern "C" void* __cdecl FUN_0008d690(int x) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(FUN_00266d90(), x);
}
