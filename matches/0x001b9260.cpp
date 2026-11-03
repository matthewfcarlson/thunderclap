#include "gen/owners.h"
struct Vec {
    int x, y, z;
};
class A {
  public:
};
A* __cdecl findA();
Vec __stdcall target() {
    A* a = findA();
    return *((Vec *)((owners::Object_1c39d0 *)a)->FUN_001c39d0());
}