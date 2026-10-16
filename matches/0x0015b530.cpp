class Angle {
    char pad[0x18];
    float angle;

  public:
    bool Set(float x);
};
bool Angle::Set(float x) {
    angle = x * 0.017453292f;
    return true;
}