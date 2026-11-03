// STATUS: equivalent (tools/equiv.py level 3: 19366 inputs, branch coverage 21/22, incomplete)
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9 @ 0x002ddb40
// pure3d::TargaHandler::vfunc_9: validate a TGA header and dispatch to the colour-mapped or true-colour reader
// equiv-conv: FUN_002dd760 esi edi
// equiv-conv: FUN_002dd890 esi ebx stack
// equiv-conv: FUN_002dd9e0 ebx edi stack
#include "compat/ptr.h"
#include "gen/pure3d.h"
#include "gen/owners.h"

struct Stream_2ddb40 {
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

extern "C" void __cdecl FUN_002dd760(void *, void *);
extern "C" void __cdecl FUN_002dd890(void *, void *, void *);
extern "C" void __cdecl FUN_002dd9e0(void *, void *, void *);

void pure3d::TargaHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { Stream_2ddb40 * stream = (Stream_2ddb40 *)__p0; void * out = (void *)__p1;

    TgaHeader hdr;
    FUN_002dd760((TgaHeader *)(&hdr), (Stream_2ddb40 *)stream);
    unsigned char type = hdr.imageType;
    if (type != 1 && type != 2)
        return;
    if (hdr.colorMapType != 0 && hdr.colorMapType != 1)
        return;
    if (hdr.bpp != 0x20 && hdr.bpp != 0x18 && hdr.bpp != 8)
        return;
    if (hdr.width > 0x1000 || hdr.height > 0x1000)
        return;
    ((owners::S_264510 *)stream)->FUN_00264510((unsigned)(hdr.idLength));
    if (type == 1)
        FUN_002dd890((TgaHeader *)(&hdr), (Stream_2ddb40 *)stream, out);
    else if (type == 2)
        FUN_002dd9e0(out, (Stream_2ddb40 *)stream, (TgaHeader *)(&hdr));
}
