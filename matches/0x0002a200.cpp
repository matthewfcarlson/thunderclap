#include "gen/owners.h"
extern "C" unsigned __int64 __cdecl Lookup(int, int, int);
extern float fallback;
class Result {
  public:
    float* Get();
};
class Owner {
  public:
    Result* Find(unsigned __int64);
    float* Query(int);
};
float* Owner::Query(int id) {
    unsigned __int64 key = Lookup(id, 0, 0);
    Result* r = Find(key);
    if (!r)
        return &fallback;
    r = ((Result *)((owners::C_35ef0 *)r)->FUN_00035ef0((hulk_intptr)0));
    if (!r)
        return &fallback;
    return r->Get();
}