#include "gen/owners.h"
struct Item {
};
struct X {
    Item* Get(unsigned __int64);
    void Fn(int id, int arg);
};
extern "C" unsigned __int64 __cdecl Hash(int, int, int);
void X::Fn(int id, int arg) {
    unsigned __int64 v = Hash(id, 0, 0);
    Item* p = Get(v);
    if (p)
        ((owners::C_36d40 *)p)->FUN_00036d40(arg);
}