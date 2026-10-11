extern "C" void __cdecl thunk_FUN_00267090(void* p);
void __cdecl operator delete(void* p);
extern int hulkfight_DebugPrintTrack_vftable;

class DebugPrintTrack {
  public:
    virtual ~DebugPrintTrack();
    char pad1[0x10];
    void* m14;
    void* m18;
    void MemberFunc();
    DebugPrintTrack* vfunc_5(unsigned char param_2);
};

DebugPrintTrack* DebugPrintTrack::vfunc_5(unsigned char param_2) {
    void* p14 = m14;
    *(void**)this = &hulkfight_DebugPrintTrack_vftable;
    thunk_FUN_00267090(p14);
    thunk_FUN_00267090(m18);
    MemberFunc();
    if (param_2 & 1) {
        operator delete(this);
    }
    return this;
}
