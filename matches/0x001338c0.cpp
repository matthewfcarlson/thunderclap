extern const float k = 0.0174533f;
class O {
  public:
    char m[0x2c];
    float value;
    char Set(float f);
};
char O::Set(float f) {
    value = f * k;
    return 1;
}
