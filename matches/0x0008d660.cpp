#include "decls/data/game/unknown.h"
// data: flag_8d660 = DAT_004dd778, obj_8d660 = DAT_004dd780

extern "C" void __cdecl init();
extern "C" void __cdecl delay(int);
struct Obj_8d660 {
    char pad[0x20];
    void run();
};
void FUN_0008d660() {
    if (!(*(unsigned char*)&DAT_004dd778)) {
        init();
        (*(Obj_8d660*)&DAT_004dd780).run();
        delay(30);
        (*(unsigned char*)&DAT_004dd778) = 1;
    }
}