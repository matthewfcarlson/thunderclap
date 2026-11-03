#include "decls/data/platform/xbox/unknown.h"
// data: gState_240c60 = DAT_004e5ce0

struct Obj_240c60 {
    char pad[0x28];
    int value;
};
struct State_240c60 {
    char pad[0x28];
    Obj_240c60* obj;
    int pad2;
    int count;
};
extern int __stdcall FUN_0020d7ff(Obj_240c60*, int, int);
extern void __stdcall FUN_0020c79c(Obj_240c60*, int, int);
extern "C" void __cdecl FUN_00240c60(int size) {
    if (size) {
        int n = FUN_0020d7ff((*(State_240c60**)&DAT_004e5ce0)->obj, 0, size);
        (*(State_240c60**)&DAT_004e5ce0)->count -= n;
        FUN_0020c79c((*(State_240c60**)&DAT_004e5ce0)->obj, 0, size);
    }
}
