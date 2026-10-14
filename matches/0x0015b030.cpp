class C_15b030 {
  public:
    char pad[0x58];
    float mDeg;
    bool Fn(float x);
};

bool C_15b030::Fn(float x) {
    mDeg = x * 0.017453292f;
    return true;
}
