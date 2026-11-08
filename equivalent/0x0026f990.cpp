// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// core::XboxDrive::vfunc_13 @ 0x0026f990
// core::XboxDrive::vfunc_13 @ 0x0026f990
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
unsigned long __stdcall FUN_002101d4(void*, unsigned long, unsigned long, unsigned long);
void __stdcall FUN_00210150(void*);
int __stdcall FUN_0021007a(void*, void*, unsigned long, void*, unsigned long);
unsigned long __stdcall FUN_002109b6(void*, unsigned long);
#include "decls/data/records.h"
namespace core {
// core::XboxDrive::vfunc_13 (records.h CoreXboxDrive): writes at an offset, growing the file first; bit 0 of the
// drive's type word (+0xbc) says it is writable
struct XboxDrive_26f990 : CoreXboxDrive {
 int vfunc_13(void*, unsigned long, unsigned long, unsigned long, void*, unsigned long, void*, unsigned long*, unsigned long);
 unsigned int FUN_0026f3e0(unsigned int);
};
int XboxDrive_26f990::vfunc_13(void* handle, unsigned long a2, unsigned long a3, unsigned long offset, void* buffer, unsigned long count, void* output, unsigned long* position, unsigned long a9) {
 if (!(*(unsigned char*)&type & 1)) return 0;
 if (offset + count > *position) {
 FUN_002101d4(handle, offset + count, 0, 0);
 FUN_00210150(handle);
 }
 if (FUN_002101d4(handle, offset, 0, 0) == offset && FUN_0021007a(handle, buffer, count, output, 0)) {
 *position = FUN_002109b6(handle, 0);
 drive.error = 0;
 return 1;
 }
 drive.error = FUN_0026f3e0(XAPILIB::GetLastError());
 return 0;
}
}
