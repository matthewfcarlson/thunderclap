#include "gen/owners.h"
class Result {
  public:
};
class Obj {
  public:
    Result* Find(__int64);
    char Run(int a, int b);
};
extern "C" __int64 __cdecl Convert(int, int, int);
char Obj::Run(int a, int b) {
    __int64 v = Convert(a, 0, 0);
    Result* r = Find(v);
    if (!r)
        return 0;
    return ((char)((owners::A_36950 *)r)->FUN_00036950(b));
}