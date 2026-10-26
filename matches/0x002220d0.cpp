#include "decls/data/engine/unknown.h"

#include "compat/ptr.h"
struct Result {
    char data[12];
};
float __cdecl FUN_00224f10(Result*);
struct Sub {
    char data[16];
    void FUN_0022b4d0(float*, Result*);
};
struct Obj {
    char pad[0x40];
    Sub sub;
    int mode;
    hulk_freg FUN_002220d0();
    void FUN_0022c3b0(float*, Result*);
};
hulk_freg Obj::FUN_002220d0() {
    Result result;
    switch (mode) {
    case 0:
    case 2:
        FUN_0022c3b0(((float*)&DAT_004c9d60), &result);
        break;
    case 1:
        sub.FUN_0022b4d0(((float*)&DAT_004c9d60), &result);
        break;
    }
    return FUN_00224f10(&result);
}