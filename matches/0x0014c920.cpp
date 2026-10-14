class C_14c920 {
  public:
    char pad[0x24];
    float mAngle;
    bool Set(float v);
};

bool C_14c920::Set(float v) {
    mAngle = v * 0.017453292519943295f;
    return true;
}
