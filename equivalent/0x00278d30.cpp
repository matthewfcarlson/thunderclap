// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// FUN_00278d30 @ 0x00278d30
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
struct Result_278d30 { unsigned state; unsigned char status; };
struct Source_278d30 { char reserved[0x244]; char data[1]; };
extern "C" void __cdecl FUN_0026b800(void *, int, void *, int, int, int, int);
struct XboxSaveDrive_278d30 {
 char reserved[0xb4]; unsigned error;
 unsigned FUN_002787c0(unsigned);
 bool FUN_002784c0(void *, unsigned);
 int FUN_00278d30(Result_278d30 *, Source_278d30 *, int, unsigned);
};
int XboxSaveDrive_278d30::FUN_00278d30(Result_278d30 *result, Source_278d30 *source, int code, unsigned value) {
 if (code == -1) {
  unsigned err = XAPILIB::GetLastError();
  if (err == 0x12) {
   result->status = 0;
   result->state = 2;
   error = 0;
   return 0;
  }
  error = FUN_002787c0(err);
  return 1;
 }
 void *data = source->data;
 if (FUN_002784c0(data, value)) {
  FUN_0026b800(&result->status, 1, data, 2, 0, 0x101, 0);
  result->state = 3;
  error = 0;
  return 0;
 }
 return 2;
}