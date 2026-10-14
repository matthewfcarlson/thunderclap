class Obj {
  public:
    char pad[0x10];
    float mF10;
    bool SetAngle(float angle);
};
const float kDegToRad = 0.0174533f;
bool Obj::SetAngle(float angle) {
    mF10 = angle * kDegToRad;
    return true;
}
