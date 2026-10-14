class Obj {
  public:
    char pad[0xac];
    float mAngle;
    bool SetAngle(float a);
};

bool Obj::SetAngle(float a) {
    mAngle = a * 0.0174532925f;
    return true;
}
