#include "gen/owners.h"
class Obj {
  public:
};
extern "C" Obj* __cdecl FUN_002d6dd0(int);
void __cdecl Target(int a, int b, int c) {
    Obj* p = FUN_002d6dd0(a);
    ((owners::X_2647e0 *)p)->FUN_002647e0((hulk_intptr)b, (hulk_intptr)c, 1, (hulk_intptr)1);
}