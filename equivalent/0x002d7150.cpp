// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 48/48)
// FUN_002d7150 @ 0x002d7150
// libpng png_read_info
#include "decls/data/engine/pure3d.h"

struct PngStruct_2d7150 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x104 - 0x64];
    unsigned int idatSize;
    char pad108[0x114 - 0x108];
    unsigned int chunk_name;
    char pad118[0x11e - 0x118];
    unsigned char colorType;
    char pad11f[0x124 - 0x11f];
    unsigned char sigBytes;
};

struct PngInfo_2d7150 {
    char pad0[0x20];
    unsigned char signature[8];
};

union PngArg {
    PngStruct_2d7150* png;
    unsigned char buf[4];
};

 // "IHDR"
 // "IDAT"
 // "IEND"
 // "PLTE"
 // "bKGD"
 // "cHRM"
 // "gAMA"
 // "hIST"
 // "oFFs"
 // "pCAL"
 // "pHYs"
 // "sBIT"
 // "sRGB"
 // "tEXt"
 // "tIME"
 // "tRNS"
 // "zTXt"

extern "C" void __cdecl FUN_002dd690(void *, void *, unsigned int);
extern "C" unsigned int __cdecl FUN_002e7500(unsigned char *);
extern "C" void __cdecl FUN_002d6c90(void *);
void FUN_002e7580(PngStruct_2d7150* png, void* buf, unsigned int n);
extern "C" void __cdecl FUN_002e82a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e69a0(void *, void *);
extern "C" void __cdecl FUN_002e84e0(void *, void *, unsigned int);
void FUN_002e8640(PngStruct_2d7150* png, PngInfo_2d7150* info, unsigned int len);
extern "C" void __cdecl FUN_002e93b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8940(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e86a0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9570(void *, void *, int);
extern "C" int __cdecl FUN_002e9790(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e9880(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e96a0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e87e0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e8f80(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9bb0(void *, void *, unsigned int);
extern "C" int __cdecl FUN_002e9ac0(void *, void *, unsigned);
extern "C" void __cdecl FUN_002e91b0(void *, void *, unsigned int);
extern "C" void __cdecl FUN_002e9c60(void *, void *, unsigned);
void FUN_002e9fc0(PngStruct_2d7150* png, PngInfo_2d7150* info, unsigned int len);

extern "C" int __cdecl FUN_002d6bb0(const char *, unsigned int, unsigned int);

void FUN_002d7150(PngArg arg, PngInfo_2d7150* info)
{
    PngStruct_2d7150* png = arg.png;
    unsigned int length;

    if (png->sigBytes < 8) {
        unsigned int numChecked = png->sigBytes;
        unsigned int numToCheck = 8 - numChecked;
        FUN_002dd690((PngStruct_2d7150 *)png, info->signature + numChecked, numToCheck);
        png->sigBytes = 8;
        if (FUN_002d6bb0((const char *)(const unsigned char *)(info->signature), numChecked, numToCheck)) {
            if (numChecked < 4 && FUN_002d6bb0((const char *)(const unsigned char *)(info->signature), numChecked, numToCheck - 4))
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Not a PNG file");
            else
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"PNG file corrupted by ASCII conversion");
        }
    }
    for (;;) {
        FUN_002dd690((PngStruct_2d7150 *)png, arg.buf, 4);
        length = FUN_002e7500((unsigned char *)(const void *)(arg.buf));
        FUN_002d6c90((PngStruct_2d7150 *)png);
        FUN_002e7580(png, &png->chunk_name, 4);

        if (png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if ((png->mode & 1) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing IHDR before IDAT");
            } else if (png->colorType == 3 && (png->mode & 2) == 0) {
                FUN_002e69a0((PngStruct_2d7150 *)png, (void *)(const char *)"Missing PLTE before IDAT");
            }
            png->idatSize = length;
            png->mode |= 4;
            return;
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
            FUN_002e9c60((PngStruct_2d7150 *)png, (PngInfo_2d7150 *)info, (unsigned int)length);
        } else {
            FUN_002e9fc0(png, info, length);
        }
    }
}
