extern const float k_1338c0 = 0.0174533f;
class O_1338c0 {
  public:
    char m[0x2c];
    float value;
    char Set(float f);
};
char O_1338c0::Set(float f) {
    value = f * k_1338c0;
    return 1;
}
