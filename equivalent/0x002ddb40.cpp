// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 21/22, incomplete)
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9: validate a TGA header and dispatch to the colour-mapped or true-colour reader
// equiv-conv: FUN_002dd760 edi esi
// equiv-conv: FUN_002dd890 stack ebx esi
// equiv-conv: FUN_002dd9e0 stack ebx
#include "gen/pure3d.h"

struct Stream_2ddb40 {
    void FUN_00264510(int skip);
};

struct TgaHeader {
    unsigned char idLength;
    unsigned char colorMapType;
    unsigned char imageType;
    char pad03[0xb];
    unsigned short width;
    unsigned short height;
    unsigned char bpp;
    unsigned char descriptor;
};

void FUN_002dd760(Stream_2ddb40 *stream, TgaHeader *hdr);
void FUN_002dd890(void *out, Stream_2ddb40 *stream, TgaHeader *hdr);
void FUN_002dd9e0(TgaHeader *hdr, void *out);

void pure3d::TargaHandler::vfunc_9(int __p0, int __p1) { Stream_2ddb40 * stream = (Stream_2ddb40 *)__p0; void * out = (void *)__p1;

    TgaHeader hdr;
    FUN_002dd760(stream, &hdr);
    unsigned char type = hdr.imageType;
    if (type != 1 && type != 2)
        return;
    if (hdr.colorMapType != 0 && hdr.colorMapType != 1)
        return;
    if (hdr.bpp != 0x20 && hdr.bpp != 0x18 && hdr.bpp != 8)
        return;
    if (hdr.width > 0x1000 || hdr.height > 0x1000)
        return;
    stream->FUN_00264510(hdr.idLength);
    if (type == 1)
        FUN_002dd890(out, stream, &hdr);
    else if (type == 2)
        FUN_002dd9e0(&hdr, out);
}
