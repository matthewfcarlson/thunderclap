// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// core::XboxDrive::vfunc_13 @ 0x0026f990
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
unsigned long __stdcall FUN_002101d4(void*, unsigned long, unsigned long, unsigned long);
void __stdcall FUN_00210150(void*);
int __stdcall FUN_0021007a(void*, void*, unsigned long, void*, unsigned long);
unsigned long __stdcall FUN_002109b6(void*, unsigned long);
namespace core {
struct XboxDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
 virtual int vfunc_13(void*, unsigned long, unsigned long, unsigned long, void*, unsigned long, void*, unsigned long*, unsigned long);
 char pad[0xb0]; unsigned long error; char pad2[4]; unsigned char flags;
 unsigned __int64 FUN_0026f3e0(unsigned long);
};
int XboxDrive::vfunc_13(void* handle, unsigned long a2, unsigned long a3, unsigned long offset, void* buffer, unsigned long count, void* output, unsigned long* position, unsigned long a9) {
 if (!(flags & 1)) return 0;
 if (offset + count > *position) {
 FUN_002101d4(handle, offset + count, 0, 0);
 FUN_00210150(handle);
 }
 if (FUN_002101d4(handle, offset, 0, 0) == offset && FUN_0021007a(handle, buffer, count, output, 0)) {
 *position = FUN_002109b6(handle, 0);
 error = 0;
 return 1;
 }
 unsigned __int64 result = FUN_0026f3e0(XAPILIB::GetLastError());
 XboxDrive* destination = reinterpret_cast<XboxDrive*>(static_cast<unsigned long>(result >> 32));
 destination->error = static_cast<unsigned long>(result);
 return 0;
}
}