// Same code shape as 0x0012b630 (propagated; names are from that function)
struct Param {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct CTrack_6b040 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

struct CClearCollisionStun_6b040 : CTrack_6b040, Param {
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

float CClearCollisionStun_6b040::GetExtent() {
    return mMaxX - mMinX;
}