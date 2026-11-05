#include "decls/data/engine/unknown.h"
// data: gFirst = DAT_004e6358, gSecond = DAT_004e635c

class Loader {
  public:
    int FUN_003469f5();
};

struct Pair {
    int a;
    int b;
};

Pair __cdecl FUN_002672f0(int a, int b, int c);

extern Loader gLoader;

void FUN_0035fc70() {
    int id = gLoader.FUN_003469f5();
    Pair p = FUN_002672f0(id, 0, 0);
    (*(int*)&DAT_004e6358) = p.a;
    (*(int*)&DAT_004e635c) = p.b;
}
