#include "gen/owners.h"
struct Item {
    char pad[0x11c];
    struct Handler* handler;
};
struct Handler {
};
extern "C" unsigned __int64 __cdecl makeKey(void*, int, int);
class Owner {
  public:
    Item* find(unsigned __int64);
    void work(void*, int);
};
void Owner::work(void* p, int x) {
    unsigned __int64 k = makeKey(p, 0, 0);
    Item* item = find(k);
    if (item && item->handler)
        ((owners::Config_447b0 *)(item->handler))->FUN_000447b0((const char *)(hulk_uintptr)(int)x);
}