// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// core::XboxSaveDrive::vfunc_0_adjbc @ 0x00279bb0
extern unsigned char *DAT_0052c270;
extern int __stdcall FUN_002109b6(const void *, int);
namespace XAPILIB { extern unsigned long __stdcall GetLastError(); }
struct AdjBC {
    int vfunc_0_adjbc(const void *name, unsigned int unused, unsigned int block, unsigned int offset, unsigned int size, void *destination, unsigned int extra);
};
struct XboxSaveDrive {
    char padding[0xb4];
    unsigned long error;
    char padding2[4];
    AdjBC reader;
    bool FUN_002788c0();
    unsigned long FUN_002787c0(unsigned long errorCode);
    bool FUN_00279490(const void *name, unsigned int block);
};
int AdjBC::vfunc_0_adjbc(const void *name, unsigned int unused, unsigned int block, unsigned int offset, unsigned int size, void *destination, unsigned int extra)
{
    XboxSaveDrive *drive = (XboxSaveDrive *)((char *)this - 0xbc);
    if (!drive->FUN_002788c0()) return 0;
    int result = FUN_002109b6(name, 0);
    if (result == -1) {
        drive->error = drive->FUN_002787c0(XAPILIB::GetLastError());
        return 0;
    }
    if ((block << 13) < (unsigned int)result) {
        if (!drive->FUN_00279490(name, block)) return 0;
        unsigned char *src = DAT_0052c270 + offset;
        unsigned char *dst = (unsigned char *)destination;
        for (unsigned int i = 0; i < size; ++i) dst[i] = src[i];
    }
    drive->error = 0;
    return 1;
}
