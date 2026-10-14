class C_146b50 {
  public:
    char pad[0x30];
    float mRad;
    bool Set(float deg);
};

bool C_146b50::Set(float deg) {
    mRad = deg * 0.017453292f;
    return true;
}
