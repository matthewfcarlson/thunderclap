#include "decls/data/game/hulkfight.h"

class T {
  public:
    T(const char*, int);
    ~T();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void f() {
    (*(T*)&DAT_004dd9d0).T::T("sound/rsd", 0);
    atexit(cleanup);
}