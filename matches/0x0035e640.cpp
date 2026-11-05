#include "decls/data/game/global.h"
// data: globalObj = DAT_004e216c

struct Obj {
    void FUN_002fb160(unsigned short, unsigned short, unsigned short);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363ff0();
void __cdecl target() {
    (*(Obj*)((char*)&DAT_004e215c + 16)).FUN_002fb160(0xffff, 0xffff, 0xffff);
    atexit(FUN_00363ff0);
}