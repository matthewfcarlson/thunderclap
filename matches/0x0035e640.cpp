#include "decls/data/game/global.h"
// data: globalObj = DAT_004e216c

struct Obj {
    void Init(int, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    (*(Obj*)((char*)&DAT_004e215c + 16)).Init(0xffff, 0xffff, 0xffff);
    atexit(cleanup);
}