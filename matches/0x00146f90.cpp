class C {
  public:
    char pad[0x40];
    float mAngle;
    bool Fn(float deg);
};

bool C::Fn(float deg) {
    mAngle = deg * 0.017453292f;
    return true;
}
