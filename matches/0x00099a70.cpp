#include "decls/data/game/global.h"
// data: gZero = DAT_003f335c

class Result;
class Item {
  public:
    Result* Get();
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
        Result* r = x->Get();
        if (r)
            p = r->Value();
    }
    return p;
}