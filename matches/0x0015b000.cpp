class C_15b000 {
  public:
    char pad[0x54];
    float mAngle;
    bool Set(float v);
};

bool C_15b000::Set(float v) {
    mAngle = v * 0.017453292f;
    return true;
}
