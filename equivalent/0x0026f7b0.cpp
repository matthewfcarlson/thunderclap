// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 11/14, incomplete)
// core::XboxDrive::vfunc_8 @ 0x0026f7b0
extern "C" int __cdecl _strncmp(const char *, const char *, unsigned int);
extern "C" int __cdecl FUN_00345804(const char *, const char *, unsigned int *, unsigned int *);
extern "C" int __stdcall FUN_00355791(unsigned int, unsigned int, int *, int *, int, int);
extern "C" int __stdcall FUN_003559b9(int, int);
extern "C" int __stdcall FUN_002109f1(const char *, unsigned int, unsigned int, int, unsigned int, int, int);
extern "C" int __stdcall FUN_002109b6(int, int);
namespace XAPILIB { extern "C" unsigned int __stdcall GetLastError(); }
namespace core {
struct XboxDrive {
 char pad[0xb4]; int status; char gap[8]; int count;
 void FUN_0026f330(const char *, char *, unsigned int);
 int FUN_0026f3e0(unsigned int);
 int vfunc_8(const char *path, int mode, unsigned char write, int *handle, int *result);
};
int XboxDrive::vfunc_8(const char *path, int mode, unsigned char write, int *handle, int *result) {
 char buffer[257];
 unsigned int first, second;
 int local0, localc;
 FUN_0026f330(path, buffer, 257);
 int h;
 if (_strncmp(buffer, "W:", 2) == 0) {
  if (FUN_00345804(buffer, "W:\\%u\\%u", &first, &second) != 2) { status = 1; return 0; }
  h = FUN_00355791(first, second, &local0, &localc, 0, 0);
  h = FUN_003559b9(local0, 0);
 } else {
  int disposition;
  if (mode == 0) disposition = 3;
  else if (mode == 1) disposition = 4;
  else if (mode == 3) disposition = 2;
  else disposition = localc;
  h = FUN_002109f1(buffer, write ? 0xc0000000 : 0x80000000, write ? 3 : 1, 0, disposition, 0x80, 0);
 }
 *handle = h;
 if (h != -1) {
  ++count;
  *result = FUN_002109b6(h, 0);
  status = 0;
  return 1;
 }
 status = FUN_0026f3e0(XAPILIB::GetLastError());
 return 0;
}
}