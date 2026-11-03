#include "gen/owners.h"
extern "C" long __cdecl atol(const char*);
class H {
  public:
};
class C_bbf20 {
  public:
    char pad[4];
    H* field;
    int F(int, char**);
};
int C_bbf20::F(int p, char** q) {
    if (field == 0)
        return -1;
    if (p != 1)
        return -1;
    if (*q != 0) {
        long v = atol(*q);
        ((owners::Obj_b4b00 *)field)->FUN_000b4b00((int)v);
    }
    return 0;
}