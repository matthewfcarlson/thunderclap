#include "decls/address.h"
struct Result {
    char pad[0x1d00];
    int value;
};
class Obj {
  public:
    Result* Lookup(__int64);
    void Set(const char*, int);
};
void Obj::Set(const char* name, int value) {
    __int64 id = FUN_002672f0(name, 0, 0);
    Result* p = Lookup(id);
    if (p)
        p->value = value;
}
