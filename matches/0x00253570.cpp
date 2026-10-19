typedef unsigned int uint;
extern void __cdecl FUN_00247550(const void*, void*);
void __fastcall FUN_0025fd10(void*);
extern char g_4e70e8;

class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEvent* vfunc_4(int flags);
    virtual void vfunc_5();
};

class SeqEventVarPitchRand : public SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventVarPitchRand* vfunc_4(int flags);
    virtual void vfunc_5();
};

SeqEventVarPitchRand* SeqEventVarPitchRand::vfunc_4(int flags) {
    FUN_0025fd10((void*)(this));
    if (flags & 1)
        FUN_00247550(&g_4e70e8, this);
    return this;
}
