#include "compat/ptr.h"
struct Item {
    char pad[8];
    hulk_intptr a;
    int b;
};
extern char buffer[];
extern void __cdecl format(char*, int, int, int);
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
    format(buffer, 0x40, p->a, p->b);
    return buffer;
}