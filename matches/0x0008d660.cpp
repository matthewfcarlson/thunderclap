#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
// data: flag_8d660 = DAT_004dd778, obj_8d660 = DAT_004dd780

extern "C" void __cdecl FUN_00267a50();
extern "C" void __cdecl FUN_0026da80(int);
struct Storage {
    void FUN_0008d480();
};
extern "C" void FUN_0008d660() {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        FUN_00267a50();
        (*(Storage*)&DAT_004dd780).FUN_0008d480();
        FUN_0026da80(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
}
