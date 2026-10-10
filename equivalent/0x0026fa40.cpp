// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 6/6)
// core::XboxDrive::vfunc_18 @ 0x0026fa40
namespace core { struct XboxDrive { char pad[0xb4]; int status; void FUN_0026f330(const char*, char*, int); int FUN_0026f4b0(const char*, char*, int*); int vfunc_18(const char* name, const char* path, int* handle, bool keep); }; }
void __stdcall FUN_0020bbc2(int);
int __stdcall FUN_00355ab5(const char*, char*);
int core::XboxDrive::vfunc_18(const char* name, const char* path, int* handle, bool keep) {
 char first[257]; char second[256];
 FUN_0026f330(name, first, 257);
 if (!keep && *handle != -1) FUN_0020bbc2(*handle);
 int value = FUN_00355ab5(first, second);
 *handle = value;
 int result = FUN_0026f4b0(path, second, handle);
 status = result;
 return result == 0;
}