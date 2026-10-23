#include "decls/address.h"
class Item {
  public:
    void Apply(int);
};
class Host {
  public:
    Item* Lookup(__int64);
    void Act(const char*, int);
};
void Host::Act(const char* s, int n) {
    __int64 k = FUN_002672f0(s, 0, 0);
    Item* p = Lookup(k);
    if (p)
        p->Apply(n);
}