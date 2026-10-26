#include "decls/data/engine/choreo2.h"
// data: g_count_22a910 = DAT_004e5abc

extern int vtable_22a910;
extern void __fastcall cleanup(void*);
struct Driver {
    int* vptr;
};
void __fastcall target(Driver* self) {
    self->vptr = &vtable_22a910;
    --(*(int*)&DAT_004e5abc);
    cleanup((void*)(self));
}
