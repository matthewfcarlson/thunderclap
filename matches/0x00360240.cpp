#include "decls/data/engine/audio.h"

struct Obj {
    void FUN_00250b20();
    Obj();
    ~Obj();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364420();
void target() {
    ((Obj*)&DAT_004e6b18)->FUN_00250b20();
    atexit(FUN_00364420);
}