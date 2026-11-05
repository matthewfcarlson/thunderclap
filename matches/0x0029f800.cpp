#include "compat/ptr.h"
#include "gen/owners.h"
class Thing_29f800 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0x10];
    int field;
};
class Item_29f800 {
  public:
    Thing_29f800* owner;
    void Apply(int, int);
};
class Manager_29f800 {
    char pad[0x24];

  public:
    int count;
    void Run(hulk_intptr);
};
void Manager_29f800::Run(hulk_intptr arg) {
    if (arg) {
        Item_29f800* p = ((Item_29f800 *)((owners::Object_29c450 *)this)->FUN_0029c450((void *)(hulk_uintptr)(int)arg));
        if (p) {
            int value = p->owner->field;
            ((owners::A_2a1180 *)(p->owner))->FUN_002a1180(value + 1);
            p->Apply(value, arg);
            ++count;
        }
    }
}