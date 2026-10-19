extern const float RADIANS_TO_DEGREES = 0.017453292f;
class Obj_16e8a0 {
  public:
    char Pad[0x48];
    float Value;
    char Fn(float x);
};
char Obj_16e8a0::Fn(float x) {
    float v = x * RADIANS_TO_DEGREES;
    Value = v;
    return 1;
}
