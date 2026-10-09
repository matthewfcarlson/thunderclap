class JointRelativeTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x18 - 4];
    JointRelativeTrack(int);
    void Init2();
};
struct Sub {
    void Init();
};
void __cdecl destroy(JointRelativeTrack*);
JointRelativeTrack::JointRelativeTrack(int flag) {
    *(int*)this = 0x417958;
    ((Sub*)((char*)this + 0x18))->Init();
    Init2();
    if (flag & 1)
        destroy(this);
}