#include "decls/data/engine/audio.h"

struct Obj {
    Obj();
    ~Obj();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void target() {
    (*(Obj*)&DAT_004e6b18).Obj::Obj();
    atexit(cleanup);
}