extern "C" char DAT_003faf9c[];
typedef unsigned char byte;
struct CSmartPropUpdateAttachmentTrack {
    char pad[0x24];
};
void __fastcall Init(void*);
void __fastcall Setup(CSmartPropUpdateAttachmentTrack*);
void __cdecl Destroy(CSmartPropUpdateAttachmentTrack*);
CSmartPropUpdateAttachmentTrack* __fastcall
CSmartPropUpdateAttachmentTrack_vfunc_5(CSmartPropUpdateAttachmentTrack* p, void*, byte b) {
    *(unsigned long*)p = ((int)DAT_003faf9c);
    Init((char*)p + 0x20);
    Init((char*)p + 0x18);
    Setup(p);
    if (b & 1)
        Destroy(p);
    return p;
}