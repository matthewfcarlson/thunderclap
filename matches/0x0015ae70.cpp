class Foo_15ae70 {
  public:
    char pad[0x28];
    float mRadians;
    bool SetDeg(float deg);
};

bool Foo_15ae70::SetDeg(float deg) {
    mRadians = deg * 0.017453292f;
    return true;
}
