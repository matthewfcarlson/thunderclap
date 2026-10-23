#include "decls/address.h"
struct Sub {
    char pad[0xe8];
    char flag;
};
struct Item {
    char pad[0x1ca0];
    Sub* sub;
    char pad2[0x22b0 - 0x1ca4];
    char flag;
};
struct Owner {
    Item* get(unsigned a, unsigned b);
    void act(const char* s);
};
void Owner::act(const char* s) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Item* p = get((unsigned)v, (unsigned)(v >> 32));
    if (p && p->sub) {
        p->flag = 0;
        p->sub->flag = 0;
    }
}