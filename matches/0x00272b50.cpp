#include "compat/ptr.h"
#include "decls/data/records.h"

// core::Drive (records.h CoreDrive): the flag at +0x5c
class X_272b50 : public CoreDrive {
};
unsigned char __fastcall target(X_272b50* self, void*) {
    return self->flag5c;
}
