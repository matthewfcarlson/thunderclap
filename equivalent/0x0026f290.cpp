// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 8/8)
// FUN_0026f290 @ 0x0026f290
#include "decls/data/engine/unknown.h"

extern void __stdcall FUN_00208b9c(char *, unsigned int *, unsigned char *, unsigned char *);
extern unsigned int __stdcall FUN_00209a8e(char *);
struct Resource {
    char pad0[0x64];
    unsigned int size;
    unsigned int count;
    unsigned int blockSize;
    char pad1[0x54];
    char name[1];
    void FUN_0026f290();
};
void Resource::FUN_0026f290()
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
        size = 0xffffffff;
    else
        size = local.foundSize;
    unsigned int n = FUN_00209a8e(local.path);
    blockSize = n ? n : 0x200;
    count = size / blockSize;
}