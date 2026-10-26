#include "compat/ptr.h"
typedef long long i64;
extern "C" i64 __cdecl lookupKey(int, int, int);
struct Item {
    char pad[0x1d30];
    hulk_intptr a, b, c;
};
class Manager {
  public:
    Item* get(i64);
    void update(int key, int a, int b, int c);
};
void Manager::update(int key, int a, int b, int c) {
    i64 id = lookupKey(key, 0, 0);
    Item* p = get(id);
    if (p) {
        p->a = a;
        p->b = b;
        p->c = c;
    }
}