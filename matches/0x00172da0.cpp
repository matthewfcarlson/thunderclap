extern "C" char DAT_00417898[];
class Part_172da0 {
  public:
    void Init();
};
extern void DestroyTrack(void*);
class JointTrackerTrack {
  public:
    virtual void* vfunc_0();
    virtual void* vfunc_1();
    virtual void* vfunc_2();
    virtual void* vfunc_3();
    virtual void* vfunc_4();
    virtual JointTrackerTrack* vfunc_5(int);
    virtual void* vfunc_6();
    virtual void* vfunc_7();
    virtual void* vfunc_8();
    virtual void* vfunc_9();
    virtual void* vfunc_10();
    char pad[0x14];
    Part_172da0 part;
    void Init();
};
JointTrackerTrack* JointTrackerTrack::vfunc_5(int f) {
    *(int*)this = ((int)DAT_00417898);
    part.Init();
    Init();
    if (f & 1)
        DestroyTrack(this);
    return this;
}