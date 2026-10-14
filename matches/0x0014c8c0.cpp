class C {
  public:
    bool Fn(float x);
    char pad[0x14];
    float mAngle;
};

bool C::Fn(float x) {
    mAngle = x * 0.0174532925f;
    return true;
}
