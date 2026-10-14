// Same code shape as 0x0005aad0 (propagated; names are from that function)
class CGrappleAttachTrack {
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
    virtual void v10();
    virtual void v11();
    virtual int vfunc_12(int);
    virtual void v13();
};
class R_6a340 {
  public:
    int invoke(CGrappleAttachTrack*, int);
};
extern R_6a340* FUN_0008d690(int);
int CGrappleAttachTrack::vfunc_12(int param) {
    R_6a340* p = FUN_0008d690(0x24);
    if (p)
        return p->invoke(this, param);
    return 0;
}