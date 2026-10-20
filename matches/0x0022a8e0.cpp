#include "gen/choreo2.h"
struct Driver_nv_22a8e0 {
    void Init();
};
extern int gCount_22a8e0;
extern int gMax_22a8e0;
extern int vtable_22a8e0;
class Driver_22a8e0 {
  public:
    int* mVtable;
};
Driver_22a8e0* __fastcall Target(Driver_22a8e0* self) {
    ((Driver_nv_22a8e0*)(((choreo2::Driver*)(self))))->Init();
    self->mVtable = &vtable_22a8e0;
    ++gCount_22a8e0;
    if (gCount_22a8e0 <= gMax_22a8e0)
        return self;
    gMax_22a8e0 = gCount_22a8e0;
    return self;
}
