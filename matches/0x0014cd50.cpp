class C {
  public:
    char pad[0x14];
    float mAngle;
    bool Set(float v);
};

bool C::Set(float v) {
    mAngle = v * 0.01745329252f;
    return true;
}
