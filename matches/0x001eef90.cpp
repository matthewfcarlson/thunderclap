#include "gen/owners.h"
class A_1eef90 {
  public:
};
extern "C" A_1eef90* __cdecl FUN_001d4c90();
void __stdcall target(void* p) {
    A_1eef90* a = FUN_001d4c90();
    ((owners::Object_1d3600 *)a)->FUN_001d3600((const char *)p, 0);
}