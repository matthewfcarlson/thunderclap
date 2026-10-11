extern "C" char DAT_00410c84[];
class ThreatDodgeTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual ThreatDodgeTrack* vfunc_5(unsigned char);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char pad[0x1c];
};
class Helper {
  public:
    void call1();
    void call2();
};
void FUN_00267090(ThreatDodgeTrack*);
ThreatDodgeTrack* ThreatDodgeTrack::vfunc_5(unsigned char param_2) {
    *(void**)this = (void*)((int)DAT_00410c84);
    ((Helper*)((char*)this + 0x20))->call1();
    ((Helper*)this)->call2();
    if (param_2 & 1)
        FUN_00267090(this);
    return this;
}