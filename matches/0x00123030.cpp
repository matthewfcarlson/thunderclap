extern "C" char DAT_0040f530[];
extern "C" void* __cdecl Alloc(unsigned int);
class StrafeCircleHBTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x24];
    StrafeCircleHBTrack();
};
class Factory_123030 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual StrafeCircleHBTrack* v5();
};
StrafeCircleHBTrack* Factory_123030::v5() {
    StrafeCircleHBTrack* p = (StrafeCircleHBTrack*)Alloc(0x28);
    if (p) {
        p->StrafeCircleHBTrack::StrafeCircleHBTrack();
        int* q = (int*)p;
        q[3] = 0;
        q[5] = 0;
        q[6] = 0;
        q[7] = 0;
        q[8] = 0;
        q[0] = ((int)DAT_0040f530);
        q[4] = (int)0xbf800000;
        q[9] = (int)0x3f800000;
        return p;
    }
    return 0;
}