class LocomotionSprintTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int vfunc_10(int a, int b, int c);
};
struct Result {
    int Init(LocomotionSprintTrack*, int);
};
extern Result* Alloc(unsigned int);
int LocomotionSprintTrack::vfunc_10(int a, int b, int c) {
    Result* p = Alloc(0x30);
    if (p)
        return p->Init(this, c);
    return 0;
}