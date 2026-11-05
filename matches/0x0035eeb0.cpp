#include "decls/data/engine/om.h"
// data: gPair = DAT_004e58d0

class Source {
  public:
    int FUN_003469f5();
};
extern Source gSource;
struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(int, int, int);
void FUN_0035eeb0() {
    int n = gSource.FUN_003469f5();
    Pair p = FUN_002672f0(n, 0, 0);
    (*(Pair*)&DAT_004e58d0) = p;
}