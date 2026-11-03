#include "decls/data/game/global.h"
// data: gZero = DAT_003f335c
#include "gen/owners.h"

class Result;
class Item {
  public:
};
class Result {
  public:
    float* Value();
};
class Host {
  public:
    char pad[0xb8];
    Item* item;
    float* Fun();
};
float* Host::Fun() {
    float* p = ((float*)&DAT_003f335c);
    Item* x = item;
    if (x) {
        Result* r = ((Result *)((owners::C_a0b70 *)x)->FUN_000a0b70());
        if (r)
            p = r->Value();
    }
    return p;
}