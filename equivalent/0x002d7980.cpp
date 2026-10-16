// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 40/40)
// FUN_002d7980 @ 0x002d7980
// libpng png_read_info
#include "decls/data/engine/pure3d.h"

struct PngStruct_2d7980 {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x114 - 0x64];
    unsigned int chunk_name;
};

struct PngInfo;

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

void FUN_002e81e0(PngStruct_2d7980* png, int a);
void FUN_002dd690(PngStruct_2d7980* png, void* buf, unsigned int n);
unsigned int FUN_002e7500(const void* buf);
void FUN_002d6c90(PngStruct_2d7980* png);
void FUN_002e7580(PngStruct_2d7980* png, void* buf, unsigned int n);
void FUN_002e82a0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e69a0(PngStruct_2d7980* png, const char* msg);
void FUN_002e84e0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e8640(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e93b0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e8940(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e86a0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9570(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9790(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9880(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e96a0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e87e0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e8f80(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9bb0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9ac0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e91b0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9c60(PngStruct_2d7980* png, PngInfo* info, unsigned int len);
void FUN_002e9fc0(PngStruct_2d7980* png, PngInfo* info, unsigned int len);

void FUN_002d7980(PngStruct_2d7980* png, PngInfo* info)
{
    unsigned char buf[4];
    unsigned int length;

    FUN_002e81e0(png, 0);
    do {
        FUN_002dd690(png, buf, 4);
        length = FUN_002e7500(buf);
        FUN_002d6c90(png);
        FUN_002e7580(png, &png->chunk_name, 4);

        if (png->chunk_name == (*(const unsigned int*)&DAT_004d1034)) {
            FUN_002e82a0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d103c)) {
            if (length > 0 || (png->mode & 8) != 0) {
                FUN_002e69a0(png, "Too many IDAT's found");
            } else {
                FUN_002e81e0(png, 0);
            }
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d104c)) {
            FUN_002e84e0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1044)) {
            FUN_002e8640(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1054)) {
            FUN_002e93b0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d105c)) {
            FUN_002e8940(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1064)) {
            FUN_002e86a0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d106c)) {
            FUN_002e9570(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1074)) {
            FUN_002e9790(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d107c)) {
            FUN_002e9880(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1084)) {
            FUN_002e96a0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d108c)) {
            FUN_002e87e0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d1094)) {
            FUN_002e8f80(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d109c)) {
            FUN_002e9bb0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10a4)) {
            FUN_002e9ac0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10ac)) {
            FUN_002e91b0(png, info, length);
        } else if (png->chunk_name == (*(const unsigned int*)&DAT_004d10b4)) {
            FUN_002e9c60(png, info, length);
        } else {
            FUN_002e9fc0(png, info, length);
        }
    } while ((png->mode & 0x10) == 0);
}
