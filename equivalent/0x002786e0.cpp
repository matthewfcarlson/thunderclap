// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_0_adj4 @ 0x002786e0
#include "compat/ptr.h"
#include "decls/data/records.h"
namespace core {
// core::XboxSaveDrive's core::Object base (+4 of records.h CoreXboxSaveDrive): the deleting destructor 0x00278a80
// on the whole drive
class XboxSaveDrive {
public:
    XboxSaveDrive* FUN_00278a80(unsigned char flags);
    XboxSaveDrive* vfunc_0_adj4(unsigned char flags);
};
XboxSaveDrive* XboxSaveDrive::vfunc_0_adj4(unsigned char flags) {
    XboxSaveDrive* drive = reinterpret_cast<XboxSaveDrive*>(reinterpret_cast<char*>(this) - (hulk_uintptr)&((CoreXboxSaveDrive*)0)->drive.vftableObject);
    return drive->FUN_00278a80(flags);
}
}
