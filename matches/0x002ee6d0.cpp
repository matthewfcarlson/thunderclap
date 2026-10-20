#include "compat/ptr.h"
class Item_2ee6d0 {
  public:
    virtual void Execute();
};
class Container_2ee6d0 {
  public:
    char pad[0x40];
    unsigned int* current;
    unsigned int* end;
    void Add(Item_2ee6d0* item);
};
void Container_2ee6d0::Add(Item_2ee6d0* item) {
    unsigned int* p = current;
    if (p < end) {
        current = p + 1;
        if (p != 0)
            *p = (hulk_uintptr)item;
    }
    item->Execute();
}