#include "decls/data/engine/movie.h"
#include "decls/data/platform/xbox/movie.h"

typedef unsigned int size_t;
class Obj {
  public:
    void FUN_00337d20(void*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364810();
void __cdecl target() {
    (*(Obj*)&DAT_0055dbb0).FUN_00337d20(((char*)&DAT_00555bb0), 0x8000);
    atexit(FUN_00364810);
}