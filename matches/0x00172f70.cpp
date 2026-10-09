typedef unsigned char u8;
class DriftToPositionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual DriftToPositionTrack* vfunc_5(u8);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x24];
    void Finish();
};
extern void __cdecl ReleaseThing(void*);
extern void __cdecl ReleaseSelf(void*);
extern void* drift_vftable;
DriftToPositionTrack* DriftToPositionTrack::vfunc_5(u8 flag) {
    *(void**)this = &drift_vftable;
    ReleaseThing(*(void**)((char*)this + 0x28));
    Finish();
    if (flag & 1)
        ReleaseSelf(this);
    return this;
}
