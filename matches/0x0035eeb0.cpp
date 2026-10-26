#include "decls/data/engine/om.h"
// data: gPair = DAT_004e58d0

class Source {
  public:
    int Get();
};
extern Source gSource;
struct Pair {
    int a, b;
};
extern Pair __cdecl Make(int, int, int);
void FUN_0035eeb0() {
    int n = gSource.Get();
    Pair p = Make(n, 0, 0);
    (*(Pair*)&DAT_004e58d0) = p;
}