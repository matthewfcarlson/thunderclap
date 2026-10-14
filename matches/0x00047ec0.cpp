class Obj {
  public:
    char Set(float x);
    char mPad[12];
    float mAngle;
};
char Obj::Set(float x) {
    mAngle = x * 0.017453292519943295f;
    return 1;
}
