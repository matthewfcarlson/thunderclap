#include "gen/owners.h"
struct Pair_2a250 {
    unsigned a, b;
};
struct Item_2a250 {
    char pad[8];
    unsigned a, b;
};
struct Owner_2a250 {
  public:
    Item_2a250* Get(unsigned, unsigned);
    char Match(const char*, const char*);
};
extern "C" Pair_2a250 __cdecl Parse(const char*, int, int);
extern "C" Pair_2a250 __cdecl Hash(const char*);
char Owner_2a250::Match(const char* s, const char* t) {
    Pair_2a250 p = Parse(s, 0, 0);
    Item_2a250* q = Get(p.a, p.b);
    if (!q)
        return 0;
    q = ((Item_2a250 *)((owners::C_35ef0 *)q)->FUN_00035ef0((hulk_intptr)0));
    if (!q)
        return 0;
    unsigned a = q->a, b = q->b;
    Pair_2a250 h = Hash(t);
    return a == h.a && b == h.b;
}