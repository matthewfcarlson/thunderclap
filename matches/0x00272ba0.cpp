#include "compat/ptr.h"
#include "decls/data/records.h"

// the library list (records.h CoreDriveLibraryList): appends (0x00277570)
struct C_272ba0 {
    void FUN_00277570(hulk_intptr);
};
// core::Drive (records.h CoreDrive): adds a cement library to its list at +0x14
struct D : CoreDrive {
    void f(hulk_intptr);
};
void D::f(hulk_intptr a0) {
    ((C_272ba0*)&libraries)->FUN_00277570(a0);
}
