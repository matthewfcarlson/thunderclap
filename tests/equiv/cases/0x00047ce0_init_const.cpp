// (regression case) matches/0x00047ce0.cpp: a named const global bound to the original pi/180 at 0x003f32b8
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
