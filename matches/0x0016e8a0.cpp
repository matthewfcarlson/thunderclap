extern const float RADIANS_TO_DEGREES = 0.0174533f;
class Obj {
  public:
    char Pad[0x48];
    float Value;
    char Fn(float x);
};
char Obj::Fn(float x) {
    float v = x * RADIANS_TO_DEGREES;
    Value = v;
    return 1;
}
