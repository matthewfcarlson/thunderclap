#include "compat/ptr.h"
#include "decls/data/records.h"

typedef unsigned char u8_273120;
// core::DriveThread (records.h CoreDriveThread): sets the requeue flag and releases the done semaphore
class Thing_273120 : public CoreDriveThread {
};
extern "C" void __cdecl FUN_0026d8a0(hulk_uintptr*);
void __fastcall Target(Thing_273120* self, void*, u8_273120 value) {
    self->requeue = value;
    FUN_0026d8a0(&self->done);
}
