extern "C" double __cdecl fabs(double);
class Callback {
  public:
    virtual void Call(int, float);
};
class ControllerInputPointXBox {
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
    virtual void v12();
    virtual void v13();
    virtual void v14(int, int);
    char pad[4];
    float mValue, mMin, mMax, mTolerance;
    int mDelta, mLast;
    void* pad20[3];
    Callback* callback;
    int context;
};
extern float __stdcall Convert(int);
void ControllerInputPointXBox::v14(int a, int b) {
    float value = Convert(b);
    if (value == mValue || !((float)fabs(value - mValue) >= mTolerance))
        mDelta = a - mLast;
    else {
        mValue = value;
        mLast = a;
        mDelta = 0;
        if (callback)
            callback->Call(context, (mMax - mMin) * value + mMin);
    }
}