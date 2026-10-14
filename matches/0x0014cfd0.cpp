class C_14cfd0 {
  public:
    char pad[0x14];
    float mAngle;
    bool Set(float v);
};

bool C_14cfd0::Set(float v) {
    mAngle = v * 0.017453292519943295f;
    return true;
}
