const float gHalfPi180 = 0.017453292f;
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
