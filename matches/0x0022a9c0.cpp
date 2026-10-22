// Same code shape as 0x0022a910 (propagated; names are from that function)
#include "gen/choreo2.h"
extern int g_count_22a9c0;
extern int vtable_22a9c0;
struct LocomotionDriver_22a9c0 {
    void cleanup();
};
struct Driver_22a9c0 {
    int* vptr;
};
void __fastcall target(Driver_22a9c0* self) {
    self->vptr = &vtable_22a9c0;
    --g_count_22a9c0;
    ((LocomotionDriver_22a9c0*)(((choreo2::LocomotionDriver*)(self))))->cleanup();
}
