const float gHalfPi180 = 0.0174533f;
class Obj {
  public:
    char Pad[12];
    float mVal;
    char Set(float x);
};
char Obj::Set(float x) {
    mVal = x * gHalfPi180;
    return 1;
}
