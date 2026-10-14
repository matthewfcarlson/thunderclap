class Obj_193450 {
  public:
    char pad[0xac];
    float mAngle;
    bool SetAngle(float a);
};

bool Obj_193450::SetAngle(float a) {
    mAngle = a * 0.0174532925f;
    return true;
}
