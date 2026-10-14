class Obj_192730 {
  public:
    char pad[0x40];
    float mAngle;
    bool Set(float angle);
};

bool Obj_192730::Set(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}
