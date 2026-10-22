extern "C" void __cdecl FUN_00267090(void* p);
void __cdecl operator delete(void* p);

extern "C" char DAT_00411344[];

class DialogueTrack_12fdd0 {
  public:
    void* vptr;
    char pad4[0x10 - 0x4];
    void* m10;
    void* m14;
    char pad18[0x1c - 0x18];
    void* m1c;
    void* m20;

    void FUN_00236d60();
    DialogueTrack_12fdd0* vfunc_5(int param);
};

DialogueTrack_12fdd0* DialogueTrack_12fdd0::vfunc_5(int param) {
    vptr = (void*)DAT_00411344;
    FUN_00267090(m10);
    FUN_00267090(m14);
    FUN_00267090(m1c);
    FUN_00267090(m20);
    FUN_00236d60();
    if (param & 1) {
        operator delete(this);
    }
    return this;
}
