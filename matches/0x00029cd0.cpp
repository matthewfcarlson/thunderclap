#include "decls/address.h"
struct Item {
    char Check();
};
struct Owner {
    Item* Find(__int64 value);
    char Test(const char* s);
};
char Owner::Test(const char* s) {
    __int64 x = FUN_002672f0(s, 0, 0);
    Item* p = Find(x);
    if (!p)
        return 0;
    return p->Check();
}