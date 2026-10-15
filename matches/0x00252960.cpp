extern void* g_name;
void __cdecl FUN_00247550(void*, void*);
void __cdecl FUN_0025fd10();
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual class SeqEventVarVolume* vfunc_4(unsigned char flags);
    virtual void v5();
};
class SeqEventVarVolume : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual class SeqEventVarVolume* vfunc_4(unsigned char flags);
    virtual void v5();
};
class SeqEventVarVolume* SeqEventVarVolume::vfunc_4(unsigned char flags) {
    FUN_0025fd10();
    if (flags & 1)
        FUN_00247550(&g_name, this);
    return this;
}
