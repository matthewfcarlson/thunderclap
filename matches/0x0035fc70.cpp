#include "decls/data/engine/unknown.h"
// data: gFirst = DAT_004e6358, gSecond = DAT_004e635c

class Loader {
  public:
    int GetId();
};

struct Pair {
    int a;
    int b;
};

Pair __cdecl GetPair(int a, int b, int c);

extern Loader gLoader;

void FUN_0035fc70() {
    int id = gLoader.GetId();
    Pair p = GetPair(id, 0, 0);
    (*(int*)&DAT_004e6358) = p.a;
    (*(int*)&DAT_004e635c) = p.b;
}
