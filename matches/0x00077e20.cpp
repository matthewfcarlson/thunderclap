const float kFactor = 0.0174533f;
class X {
  public:
    char Set(float v);
    char mPad[0x18];
    float mVal;
};
char X::Set(float v) {
    mVal = v * kFactor;
    return 1;
}
