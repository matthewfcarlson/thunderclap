// (regression case, wrong) the same with 0.0174533f (0x3c8efa39, 4 ulps off): byte match, level 3 reads the original; must fail
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
