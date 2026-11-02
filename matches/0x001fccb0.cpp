#include "compat/ptr.h"
struct Item {
    char pad[8];
    hulk_intptr a;
    int b;
};
extern char buffer[];
extern "C" void __cdecl FUN_00096d50(char*, int, int, int);
class CTriggerVolumeManager_1fccb0 {
    char pad[0x238];
    int count;
    Item* items[1];

  public:
    char* get(int index);
};
char* CTriggerVolumeManager_1fccb0::get(int index) {
    if (index >= count)
        return 0;
    Item* p = items[index];
    FUN_00096d50(buffer, 0x40, p->a, p->b);
    return buffer;
}