class C {
  public:
    bool Set(float deg);
    char pad[0x2c];
    float mRad;
};

bool C::Set(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}
