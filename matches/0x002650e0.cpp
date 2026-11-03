// Same code shape as 0x002366e0 (propagated; names are from that function)
#include "gen/owners.h"
class Item_2650e0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_2650e0 {
  public:
};
class Temp_2650e0 {
    char pad[8];

  public:
    void Init(Owner_2650e0*);
    Item_2650e0* First();
    Item_2650e0* Next();
};
void __fastcall FUN_002650e0(Owner_2650e0* self) {
    Temp_2650e0 t;
    t.Init(self);
    Item_2650e0* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    ((owners::X_231070 *)self)->FUN_00231070();
}