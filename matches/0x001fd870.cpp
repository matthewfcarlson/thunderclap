#include "gen/owners.h"
typedef unsigned __int64 U64;
struct Data {
    int a, b, c;
};
U64 __cdecl Convert(int);
class Item {
  public:
};
class CTriggerVolumeManager_1fd870 {
  public:
    Item* Find(U64);
    bool Do(int, Data);
};
bool CTriggerVolumeManager_1fd870::Do(int n, Data d) {
    U64 id = Convert(n);
    Item* item = Find(id);
    if (!item)
        return false;
    ((owners::Target_1fb990 *)item)->FUN_001fb990((const int *)(Data *)(&d));
    return true;
}