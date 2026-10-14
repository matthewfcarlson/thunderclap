class C_15ab40 {
  public:
    char pad[0x18];
    float mRad;
    bool Set(float deg);
};

bool C_15ab40::Set(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}
