const float kDegToRad = 0.017453292f;
class Obj {
  public:
    char pad[0x40];
    float angle;
    char Set(float v);
};
char Obj::Set(float v) {
    angle = v * kDegToRad;
    return 1;
}