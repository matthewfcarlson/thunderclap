class C {
  public:
    char pad[0x30];
    float mRad;
    bool Set(float deg);
};

bool C::Set(float deg) {
    mRad = deg * 0.017453292f;
    return true;
}
