class C {
  public:
    char pad[0x14];
    float mAngle;
    bool SetDeg(float deg);
};

bool C::SetDeg(float deg) {
    mAngle = deg * 0.0174532925f;
    return true;
}
