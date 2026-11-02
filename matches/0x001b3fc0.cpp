#include "decls/data/game/global.h"

struct Helper_1b3fc0 {
    void init(int);
};
extern "C" void __cdecl FUN_002fa580(int);
extern "C" void __cdecl FUN_001b3c50();
extern "C" void __cdecl FUN_002fa4e0(int, int, int);
struct Obj_1b3fc0 {
    char pad[8];
    int field;
};
void __fastcall target(Obj_1b3fc0* self) {
    if ((*(int*)&DAT_004e215c) == 0) {
        (*(int*)&DAT_004e215c) = (*(int*)&DAT_00554c10);
        ((Helper_1b3fc0*)(*(int*)&DAT_00554c10))->init(0x40000000);
    }
    if (self->field == 0)
        self->field = (*(int*)&DAT_00554c14);
    FUN_002fa580(1);
    FUN_001b3c50();
    FUN_002fa4e0(0x14, 0x19, 500);
}