class C_14ce20 {
  public:
    char pad[0x18];
    float mRadians;
    bool Convert(float deg);
};

bool C_14ce20::Convert(float deg) {
    mRadians = deg * 0.0174532925f;
    return true;
}
