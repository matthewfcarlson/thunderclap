#include "gen/choreo2.h"
#include "decls/data/engine/choreo2.h"
// data: gCount_22a8e0 = DAT_004e5abc
struct Driver_nv_22a8e0 {
    void Init();
};
extern int vtable_22a8e0;
class Driver_22a8e0 {
  public:
    int* mVtable;
};
Driver_22a8e0* __fastcall Target(Driver_22a8e0* self) {
    ((Driver_nv_22a8e0*)(((choreo2::Driver*)(self))))->Init();
    self->mVtable = &vtable_22a8e0;
    ++(*(int*)&DAT_004e5abc);
    if ((*(int*)&DAT_004e5abc) <= (*(int*)&DAT_004e5ac0))
        return self;
    (*(int*)&DAT_004e5ac0) = (*(int*)&DAT_004e5abc);
    return self;
}
