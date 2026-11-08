#include "compat/ptr.h"
#include "decls/data/records.h"

// the library list (records.h CoreDriveLibraryList): unlinks (0x002775b0)
struct C_272bb0 {
    void FUN_002775b0(hulk_intptr);
};
// core::Drive (records.h CoreDrive): removes a cement library from its list at +0x14
struct D : CoreDrive {
    void f(hulk_intptr);
};
void D::f(hulk_intptr a0) {
    ((C_272bb0*)&libraries)->FUN_002775b0(a0);
}
