class C {
  public:
    char pad[0x58];
    float mDeg;
    bool Fn(float x);
};

bool C::Fn(float x) {
    mDeg = x * 0.017453292f;
    return true;
}
