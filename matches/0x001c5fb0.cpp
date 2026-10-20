#include "compat/ptr.h"
class Item_1c5fb0 {
  public:
    char pad[8];
};
class Checker_1c5fb0 {
  public:
    bool test(void*);
};
class Owner_1c5fb0 {
  public:
    char pad0[4];
    Item_1c5fb0** items;
    unsigned int count;
    hulk_intptr Find(Checker_1c5fb0*);
};
hulk_intptr Owner_1c5fb0::Find(Checker_1c5fb0* arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (arg->test((char*)items[i] + 8))
                return (hulk_intptr)items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}
