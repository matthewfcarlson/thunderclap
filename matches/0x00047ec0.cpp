class Obj_47ec0 {
  public:
    char Set(float x);
    char mPad[12];
    float mAngle;
};
char Obj_47ec0::Set(float x) {
    mAngle = x * 0.017453292519943295f;
    return 1;
}
