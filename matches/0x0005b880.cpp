class CGrappleSequenceTrack {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4();
    virtual CGrappleSequenceTrack* vfunc_5(unsigned char);
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10();
    char pad[0x1c-4];
};
void __fastcall FUN_00236fd0(void*);
void __fastcall FUN_00234150(void*);
void __fastcall FUN_00236d60(CGrappleSequenceTrack*);
void __cdecl thunk_FUN_00267090(CGrappleSequenceTrack*);
CGrappleSequenceTrack* CGrappleSequenceTrack::vfunc_5(unsigned char p) {
    *(unsigned long*)this = 0x3f9a2c;
    FUN_00236fd0((char*)this + 0x1c);
    FUN_00234150((char*)this + 0xc);
    FUN_00236d60(this);
    if (p & 1) thunk_FUN_00267090(this);
    return this;
}