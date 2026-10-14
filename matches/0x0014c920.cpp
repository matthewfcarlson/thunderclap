class C {
  public:
    char pad[0x24];
    float mAngle;
    bool Set(float v);
};

bool C::Set(float v) {
    mAngle = v * 0.017453292519943295f;
    return true;
}
