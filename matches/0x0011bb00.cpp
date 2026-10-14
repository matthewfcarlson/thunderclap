class X_11bb00 {
  public:
    char pad[0x18];
    float value;
    bool Convert(float degrees);
};
bool X_11bb00::Convert(float degrees) {
    value = degrees * (1.f / 57.29578f);
    return true;
}
