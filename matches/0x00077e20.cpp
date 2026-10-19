const float kFactor = 0.017453292f;
class X_77e20 {
  public:
    char Set(float v);
    char mPad[0x18];
    float mVal;
};
char X_77e20::Set(float v) {
    mVal = v * kFactor;
    return 1;
}
