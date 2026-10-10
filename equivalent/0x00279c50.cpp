// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 6/6)
// core::XboxSaveDrive::vfunc_0_adjc0 @ 0x00279c50
typedef unsigned int uint;
extern unsigned char* DAT_0052c270;
extern int DAT_0052c27c;
extern int __stdcall FUN_002109b6(void*, int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned);
namespace XAPILIB { extern unsigned long __stdcall GetLastError(); }
struct XboxSaveDrive;
struct SaveWriter {
    int vfunc_0_adjc0(void* path, int unused, void* data, unsigned offset, unsigned length, const void* source, int* result, int unused2);
};
struct XboxSaveDrive {
    char pre[0xb4];
    int error;
    char middle[8];
    SaveWriter writer;
    bool FUN_002788c0();
    int FUN_002787c0(unsigned long);
    bool FUN_00279490(void*, void*);
};
int SaveWriter::vfunc_0_adjc0(void* path, int unused, void* data, unsigned offset, unsigned length, const void* source, int* result, int unused2) {
    XboxSaveDrive* drive = (XboxSaveDrive*)((char*)this - 0xc0);
    if (!drive->FUN_002788c0()) return 0;
    int value = FUN_002109b6(path, 0);
    if (value == -1) {
        drive->error = drive->FUN_002787c0(XAPILIB::GetLastError());
        return 0;
    }
    if (!drive->FUN_00279490(path, data)) return 0;
    DAT_0052c27c = 0;
    memcpy(DAT_0052c270 + offset, source, length);
    unsigned n = (unsigned)value + 0x2013;
    unsigned quotient = (unsigned)(((unsigned __int64)n * 0x7fb031e1) >> 44);
    DAT_0052c27c = 2;
    *result = value - quotient * 20;
    drive->error = 0;
    return 1;
}