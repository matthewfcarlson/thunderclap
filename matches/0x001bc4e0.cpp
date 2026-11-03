#include "gen/owners.h"
class Obj_1bc4e0 {
  public:
    void DoA();
    void DoB();
};
Obj_1bc4e0* __cdecl GetObj();
void __fastcall target(Obj_1bc4e0* self) {
    Obj_1bc4e0* saved = self;
    GetObj()->DoA();
    GetObj()->DoB();
    ((owners::Thing_1c3770 *)(GetObj()))->FUN_001c3770((hulk_intptr)(Obj_1bc4e0 *)saved);
}
