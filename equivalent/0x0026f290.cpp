// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 8/8)
// FUN_0026f290 @ 0x0026f290
#include "decls/data/engine/unknown.h"

#include "decls/data/records.h"
extern void __stdcall FUN_00208b9c(char *, unsigned int *, unsigned char *, unsigned char *);
extern unsigned int __stdcall FUN_00209a8e(char *);
// core::XboxDrive (records.h CoreXboxDrive): the medium's size and sector size, by the drive's name
struct XboxDrive_26f290 : CoreXboxDrive {
    void FUN_0026f290();
};
void XboxDrive_26f290::FUN_0026f290()
{
    struct Locals {
        char path[4];
        unsigned int foundSize;
        unsigned int error;
        unsigned char first[8];
        unsigned char second[8];
    } local;
    char *out = local.path;
    const char *in = name;
    char c;
    do {
        c = *in++;
        *out++ = c;
    } while (c);
    out[-1] = (char)(*(unsigned short*)&DAT_0042ab54);
    out[0] = (char)((*(unsigned short*)&DAT_0042ab54) >> 8);
    FUN_00208b9c(local.path, &local.foundSize, local.second, local.first);
    if (local.error)
        drive.size = 0xffffffff;
    else
        drive.size = local.foundSize;
    unsigned int n = FUN_00209a8e(local.path);
    drive.sectorSize = n ? n : 0x200;
    drive.count = drive.size / drive.sectorSize;
}