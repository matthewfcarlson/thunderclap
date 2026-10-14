class C {
  public:
    char pad[0x4c];
    float mRad;
    bool SetDeg(float deg);
};

bool C::SetDeg(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}
