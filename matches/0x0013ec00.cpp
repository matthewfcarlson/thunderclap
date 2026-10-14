class X {
  public:
    char pad[0x40];
    float angle;
    bool SetAngleDegrees(float degrees);
};

bool X::SetAngleDegrees(float degrees) {
    angle = degrees * 0.017453292519943295f;
    return true;
}
