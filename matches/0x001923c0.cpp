extern "C" const float __real_3c8efa35 = 0.0174533f;
class X_1923c0 {
  public:
    char Pad[0x70];
    float Value;
    char Set(float x);
};
char X_1923c0::Set(float x) {
    Value = x * __real_3c8efa35;
    return 1;
}
