#include "decls/address.h"
struct Item {
    char pad[0x1cfc];
    int value;
};
struct Obj {
    Item* Set(unsigned long long v);
    void Func(char* name, int val);
};
void Obj::Func(char* name, int val) {
    unsigned long long v = FUN_002672f0(name, 0, 0);
    Item* p = Set(v);
    if (p)
        p->value = val;
}