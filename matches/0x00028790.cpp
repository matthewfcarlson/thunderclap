#include "decls/address.h"
typedef unsigned __int64 U64;
class Item {
  public:
    void fn(int, int);
};
class Owner {
  public:
    Item* lookup(U64);
    void target(const char*, int, int);
};
void Owner::target(const char* s, int a, int b) {
    U64 n = FUN_002672f0(s, 0, 0);
    Item* p = lookup(n);
    if (p)
        p->fn(a, b);
}