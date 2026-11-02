#include "decls/data/engine/physics.h"
// data: gManager = DAT_00554c30

typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_0027b020(int);
class Manager {
  public:
    void send(U64, int, int, int, int);
};
extern "C" void __cdecl FUN_002f28d0(int a, int b, int c, int d, int e) {
    (*(Manager**)&DAT_00554c30)->send(FUN_0027b020(a), b, c, d, e);
}
