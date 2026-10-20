#include "compat/ptr.h"
extern "C" char DAT_003faf9c[];
typedef unsigned char byte_62e80;
struct CSmartPropUpdateAttachmentTrack {
    char pad[0x24];
};
void __fastcall Init(void*);
void __fastcall Setup(CSmartPropUpdateAttachmentTrack*);
void __cdecl Destroy(CSmartPropUpdateAttachmentTrack*);
CSmartPropUpdateAttachmentTrack* __fastcall
CSmartPropUpdateAttachmentTrack_vfunc_5(CSmartPropUpdateAttachmentTrack* p, void*, byte_62e80 b) {
    *(hulk_ulongptr*)p = ((hulk_intptr)DAT_003faf9c);
    Init((char*)p + 0x20);
    Init((char*)p + 0x18);
    Setup(p);
    if (b & 1)
        Destroy(p);
    return p;
}