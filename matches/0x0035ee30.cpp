#include "decls/data/game/global.h"
// data: g_resource = DAT_004e58b8

class Resource {
  public:
    Resource(const char*, int);
};
extern "C" void __cdecl cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl initResource() {
    (*(Resource*)&DAT_004e58b8).Resource::Resource("sound/rsd", 0);
    atexit(cleanup);
}