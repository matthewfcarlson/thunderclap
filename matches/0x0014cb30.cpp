class C_14cb30 {
  public:
    char pad[0x14];
    float mAngle;
    bool SetDeg(float deg);
};

bool C_14cb30::SetDeg(float deg) {
    mAngle = deg * 0.0174532925f;
    return true;
}
