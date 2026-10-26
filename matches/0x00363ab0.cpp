#include "decls/data/engine/movie.h"
#include "decls/data/platform/xbox/movie.h"

typedef unsigned int size_t;
class Obj {
  public:
    void Init(void*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void __cdecl target() {
    (*(Obj*)&DAT_0055dbb0).Init(((char*)&DAT_00555bb0), 0x8000);
    atexit(cleanup);
}