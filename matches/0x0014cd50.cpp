class C_14cd50 {
  public:
    char pad[0x14];
    float mAngle;
    bool Set(float v);
};

bool C_14cd50::Set(float v) {
    mAngle = v * 0.01745329252f;
    return true;
}
