#include "decls/data/engine/physics.h"
// data: gManager = DAT_00554c30

typedef unsigned __int64 U64;
extern U64 __cdecl make(int);
class Manager {
  public:
    void send(U64, int, int, int, int);
};
void __cdecl target(int a, int b, int c, int d, int e) {
    (*(Manager**)&DAT_00554c30)->send(make(a), b, c, d, e);
}
