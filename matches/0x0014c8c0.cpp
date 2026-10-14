class C_14c8c0 {
  public:
    bool Fn(float x);
    char pad[0x14];
    float mAngle;
};

bool C_14c8c0::Fn(float x) {
    mAngle = x * 0.0174532925f;
    return true;
}
