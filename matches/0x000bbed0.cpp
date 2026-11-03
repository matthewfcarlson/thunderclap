#include "gen/owners.h"
class Other {
  public:
};
class Obj {
  public:
    int dummy;
    Other* ptr;
    int target(void* a, void* b);
};
int Obj::target(void* a, void* b) {
    Other* p = ptr;
    if (!p)
        return -1;
    if (a)
        return -1;
    ((owners::Owner_b5a30 *)p)->FUN_000b5a30();
    return 0;
}