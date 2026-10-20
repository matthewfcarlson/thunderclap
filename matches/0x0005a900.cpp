// Same code shape as 0x0012b630 (propagated; names are from that function)
struct Param {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct CTrack_5a900 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

struct CGrappleLocoStrafe4Track_5a900 : CTrack_5a900, Param {
  public:
    virtual void vfunc0();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual float GetExtent();
    virtual void vfunc10();

    int mFlags;
    float mMinX;
    float mMaxX;
    float mWidth;
    float mHeight;
};

float CGrappleLocoStrafe4Track_5a900::GetExtent() {
    return mMaxX - mMinX;
}