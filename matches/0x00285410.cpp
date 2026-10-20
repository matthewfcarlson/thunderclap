#include "compat/ptr.h"
class Item_285410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Match(int);
};
class Container_285410 {
  public:
    char pad[0x14];
    unsigned int count;
    Item_285410* items[1];
    unsigned int Find(int value);
};
unsigned int Container_285410::Find(int value) {
    unsigned int i = 0;
    while (i < count) {
        if (items[i]->Match(value) == true)
            return (hulk_uintptr)items[i];
        ++i;
    }
    return 0;
}