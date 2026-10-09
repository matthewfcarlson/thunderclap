extern void* OmHalStream_vftable;
struct Base { void Init(); };
struct OmHalStream { void* vf; char pad[0x1b8]; OmHalStream(unsigned char); };
extern void __cdecl Cleanup(void*, OmHalStream*);
OmHalStream::OmHalStream(unsigned char flag) {
    vf = &OmHalStream_vftable;
    ((Base*)((char*)this + 0x1bc))->Init();
    if (flag & 1) Cleanup(&OmHalStream_vftable, this);
}
