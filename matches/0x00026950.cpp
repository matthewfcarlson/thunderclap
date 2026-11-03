#include "gen/owners.h"
class Item {
  public:
};
extern "C" __int64 __cdecl Lookup(int, int, int);
class Owner {
  public:
    Item* Get(__int64);
    char Run(int, int);
};
char Owner::Run(int key, int value) {
    __int64 id = Lookup(key, 0, 0);
    Item* item = Get(id);
    if (!item)
        return 0;
    ((owners::Obj_35930 *)item)->FUN_00035930(value);
    return 1;
}