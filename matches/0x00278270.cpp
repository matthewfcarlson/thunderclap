#include "decls/data/records.h"
#include "gen/core.h"

// the drive's name (records.h CoreXboxSaveDrive)
void* core::XboxSaveDrive::vfunc_4() {
    return ((CoreXboxSaveDrive*)this)->name;
}
