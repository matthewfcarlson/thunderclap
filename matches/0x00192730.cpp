class Obj {
  public:
    char pad[0x40];
    float mAngle;
    bool Set(float angle);
};

bool Obj::Set(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}
