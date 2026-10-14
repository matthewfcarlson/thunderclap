const float gHalfPi180 = 0.0174533f;
class Obj_47ce0 {
  public:
    char Pad[12];
    float mVal;
    char Set(float x);
};
char Obj_47ce0::Set(float x) {
    mVal = x * gHalfPi180;
    return 1;
}
