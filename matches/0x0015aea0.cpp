class C_15aea0 {
  public:
    bool Set(float deg);
    char pad[0x2c];
    float mRad;
};

bool C_15aea0::Set(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}
