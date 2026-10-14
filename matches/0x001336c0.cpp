class Obj {
  public:
    char pad[0x14];
    float mAngle;
    bool Set(float v);
};

bool Obj::Set(float v) {
    mAngle = v * 0.017453292f;
    return true;
}
