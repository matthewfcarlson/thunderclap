#include "compat/ptr.h"
#include "decls/data/records.h"

// core::Drive (records.h CoreDrive): its library list at +0x14
struct Obj_272bc0 : CoreDrive {
};
void* __fastcall target(Obj_272bc0* self) {
    return &self->libraries;
}
