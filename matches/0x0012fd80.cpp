extern "C" char DAT_00411314[];
extern "C" void __cdecl free_a(void*);
extern "C" void __cdecl free_b(void*);

class NISSoundTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual NISSoundTrack* vfunc_5(unsigned char param);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();

    void FUN_00236d60(); // thiscall member, matches mov ecx,esi; call

    NISSoundTrack* vfunc_5_impl(unsigned char param);

    char pad0[0xC]; // offsets 4..0xF
    void* m10;      // 0x10
    void* m14;      // 0x14
    void* m18;      // 0x18
};

NISSoundTrack* NISSoundTrack::vfunc_5_impl(unsigned char param) {
    *(void**)this = (void*)((int)DAT_00411314);
    free_a(m10);
    free_a(m14);
    free_a(m18);
    FUN_00236d60();
    if (param & 1) {
        free_b(this);
    }
    return this;
}
