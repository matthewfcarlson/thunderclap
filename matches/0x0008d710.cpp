#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
// data: flag_8d710 = DAT_004dd778, object_8d710 = DAT_004dd780

#include "compat/ptr.h"
extern "C" void __cdecl FUN_00267a50();
extern "C" void __cdecl FUN_0026da80(int);
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
struct Storage {
    void FUN_0008d480();
};
extern "C" void* __cdecl FUN_0008d710(hulk_intptr size, int heap) {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
    return FUN_00266e00(heap, size);
}
